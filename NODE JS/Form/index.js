// *1. requiring packages
const express = require("express");
const mongoose = require("mongoose");
const app = express();
const path = require("path");
app.set('views', './views');
app.set('view engine', 'ejs');
// *2. database

// mongoose
//   .connect()
//   .then(function () {
//     console.log("db connect");
//   })
//   .catch(function (err) {
//     console.log(err);
//   });

// const productModel=require();
// *3. session and auth

// *4. config
app.use(express.static(path.join(__dirname, "public")));
app.use(express.urlencoded());
app.set("view engin", "ejs");

// *5. api
//http->request:get ,post,put,patch,delete
//app.method(endpoint,callback);
//res.send(raw data);
// app.get("/user/:name", function (req, res) {
//   res.render("index", { variable });
// });

app.get("/form", function (req, res) {
  res.render("form");
});

app.get("/formsubmit", function (req, res) {
  res.send(req.query);
});

app.post("/formsubmit", function (req, res) {
  let userEmail = req.body.email;
  if (!check(userEmail)) {
    res.redirect("/form", { error: "wrong email format ,errorCode:200" });
  }
  let userPassword = req.body.password;
  let userImage = req.body.image;
  res.render("show", { userEmail, userPassword, userImage });
});

//to make server listen to request an a port
//app.listen(port number)
app.listen(3000, function () {
  console.log("server is running in port 3000");
});
