const express = require("express");
const mongoose = require("mongoose");
const methodOverride=require('method-override');
const app = express();
const path = require("path");

let uri='mongodb+srv://memihirbhawsar:mihir123@databaseforproject.049itfu.mongodb.net/?retryWrites=true&w=majority';
mongoose
  .connect(uri)
  .then(function () {
    console.log("db connect");
  })
  .catch(function (err) {
    console.log(err);
  });


app.use(express.static(path.join(__dirname, "public")));
app.use(express.urlencoded({ extended: true }));
app.set('views', './views');
app.use(methodOverride('_method'));

app.set('view engine', 'ejs');
 
const productRouter=require('./routes/product');
app.use(productRouter);

app.listen(3000, function () {
  console.log("server is running in port 3000");
});
