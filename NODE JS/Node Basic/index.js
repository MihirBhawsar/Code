// *1. requiring packages
const express = require("express");
const app = express();
const path = require('path'); 
// app.set('views', './views');
// app.set('view engine', 'ejs');
// *2. database

// *3. session and auth

// *4. config
app.use(express.static(path.join(__dirname, 'public')));

// *5. api
//http->request:get ,post,put,patch,delete
//app.method(endpoint,callback);
//res.send(raw data);
app.get("/", function (req, res) {
  res.send("Server is working");
});
app.get("/hello", function (req, res) {
  console.log(req.query);
  // res.send("Hello");
  res.send(`name ${req.query.name}`);
});
app.get("/greet/:name", function (req, res) {
  console.log(req.params);
  // res.send(`name ${req.params.name}`);
  // res.json(`name ${req.params.name}`);
  // let name=req.params.name;
  let {name}=req.params;//destructuring
  const paragraph ='<div>this is a <em>para</em></div>';
  res.render('index.ejs',{username:name,age:5,color:'blue',paragraph});

});
app.get("*", function (req, res) {
  // res.send("Error 404");
  // res.redirect(url);
  res.redirect('/');
});

//to make server listen to request an a port
//app.listen(port number)
app.listen(3000, function () {
  console.log("server is running in port 3000");
});
