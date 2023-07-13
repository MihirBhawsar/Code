const express = require("express");
const mongoose = require("mongoose");
const methodOverride = require("method-override");
const moment = require("moment");
const path = require("path");
const app = express();
const session = require("express-session");
const flash=require('connect-flash');
const passport = require("passport");
const LocalStrategy = require("passport-local");
require("dotenv").config();
mongoose
  .connect(process.env.MONODB_URL)
  .then(() => {
    console.log("DataBase connected");
  })
  .catch((error) => {
    console.log(error);
  });

app.use(
  session({
    secret: process.env.SESSION_SECRET,
    resave: false,
    saveUninitialized: true,
    cookie: {
      httpOnly: true,
      maxAge: 1000 * 60 * 60 * 24 * 2,
      // secure: true
    },
  })
);
//google setup
const {passportInit}=require('./config/passport');
passportInit(app);

// ! server configuration
app.use(flash());
app.set("view engine", "ejs");
app.use(methodOverride("_method"));
app.use(express.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, "public")));


// global middleware
app.use((req,res,next)=>{
  res.locals.moment =moment,
  res.locals.error=req.flash('error'),
  res.locals.success=req.flash('success'),
  res.locals.currentUser=req.user;
  next();
})


// app.use(passport.initialize());
// app.use(passport.session());
// passport.use(new LocalStrategy(User.authenticate()));
// passport.serializeUser(User.serializeUser());
// passport.deserializeUser(User.deserializeUser());


app.use((req, res, next) => {
  res.locals.moment = moment;
  next();
});

const User = require("./models/users");
const hotelRoutes = require("./routes/hotels");
const reviewRoutes = require("./routes/reviews");
const oAuth = require("./routes/oAuth");
const authRoutes = require("./routes/auth");
app.use(hotelRoutes);
app.use(reviewRoutes);
app.use(oAuth);
app.use(authRoutes);

const port = process.env.PORT;
app.listen(port, () => {
  console.log("server started");
});
