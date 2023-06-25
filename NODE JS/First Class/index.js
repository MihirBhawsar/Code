//we created our own server using node js

// const http=require("http");

// const server=http.createServer(function(req,res){
//     //http header
//     res.writeHead(200,{'Content-Type':'text/plain'});
//     res.end("Hello World , i am learning NodeJs");
// }).listen(8000);

// console.log("My server has started running");

// const http = require("http");

// const server = http.createServer(function (req, res) {
//   console.log("the request has been mae from browser to server");

//   //http header
//   res.writeHead(200, { "Content-Type": "text/html" });
//   res.write("<h1>Hello world</h1>");
//   res.write("<h1>i am learning NodeJs</h1>");
//   res.end();
// });

// server.listen(3333, "localhost", () => {
//   console.log("My server has started running");
// });

//html file read
// const fs = require("fs");
// const http = require("http");

// const server = http.createServer(function (req, res) {
//   console.log("the request has been mae from browser to server");

//   //http header
//   res.writeHead(200, { "Content-Type": "text/html" });
//   fs.readFile('./Views/SignUp.html', (err, fileData) => {
//     if (err) {
//       console.error(err);
//     } else {
//       res.write(fileData);
//       res.end();
//     }
//   });
// });

// server.listen(3333, "localhost", () => {
//   console.log("My server has started running");
// });

//read multiple html file

const fs = require('fs');
const http = require('http');

const server = http.createServer(function (req, res) {
  console.log('the request has been mae from browser to server');

  //http header
  res.writeHead(200, { 'Content-Type': 'text/html' });
  let path = './ViewS';
  switch (res.url) {
    case '/':
      path += '/SignUp.html';
    break;
    case '/food':
      path += '/Food.html';
    break;
    case '/lottery':
      path += '/Lottery.html';
    break;
    default:
      path += '/404.html';
  };
  fs.readFile(path, (err, fileData) => {
    if (err) {
      console.error(err);
    } else {
      res.write(fileData);
      res.end();
    }
  });
});

server.listen(3333, "localhost", () => {
  console.log("My server has started running");
});
