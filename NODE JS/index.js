//we created our own server using node js

// const http=require("http");

// const server=http.createServer(function(req,res){
//     //http header
//     res.writeHead(200,{'Content-Type':'text/plain'});
//     res.end("Hello World , i am learning NodeJs");
// }).listen(8000);

// console.log("My server has started running");

const http = require("http");

const server = http.createServer(function (req, res) {
  console.log("the request has been mae from browser to server");

  //http header
  res.writeHead(200, { "Content-Type": "text/html" });
  res.write("<h1>Hello world</h1>");
  res.write("<h1>i am learning NodeJs</h1>");
  res.end();
});

server.listen(3333, "localhost", () => {
  console.log("My server has started running");
});
