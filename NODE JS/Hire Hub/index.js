const express = require("express");
const mongoose = require("mongoose");
const path = require("path");
const methodOverride = require("method-override");
const session = require("express-session");
const passport = require("passport");
const localStrategy = require("passport-local");
const flash = require("connect-flash");

require("dotenv").config();
const app = express();

mongoose
  .connect(process.env.DB_URL)
  .then(() => {
    console.log("DB connect");
  })
  .catch((error) => {
    console.log(error);
  });

// ! Session setup

app.use(
  session({
    secret: process.env.SESSION_SECRET,
    resave: false,
    saveUninitialized: true,
    cookie: {
      httpOnly: true,
      // secure: true,
      maxAge: 1000 * 60 * 60 * 24 * 2
    }
  })
);


const User = require("./models/user");

//passport setup
app.use(passport.initialize());
app.use(passport.session());
passport.use(new localStrategy(User.authenticate()));
passport.serializeUser(User.serializeUser());
passport.deserializeUser(User.deserializeUser());

//server setup
//flash setup
app.use(flash);

//serving static files
app.use(express.static(path.join(__dirname, "public")));
//form data parsing
app.use(express.urlencoded({ extended: true }));
//remove ejs extension
app.set("view engine", "ejs");
app.use(methodOverride('_method'));

app.use((req, res, next) => {
  res.locals.success = req.flash.success;
  res.locals.error = req.flash.error;
  next();
});

app.get("/", (req, res) => {
  res.send("working");
});

const jobRoutes = require("./routes/jobs");
const notificationRoutes = require("./routes/notification");
const authRoutes = require("./routes/auth");
const userRoutes = require("./routes/user");

app.use(jobRoutes);
app.use(notificationRoutes);
app.use(authRoutes);
app.use(userRoutes);

app.listen(3000, () => {
  console.log("server running on port 3000");
});
