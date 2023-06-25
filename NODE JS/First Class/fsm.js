//asynchronously
const fs = require("fs");

// console.log("before");
// fs.readFile('file.txt', function (error, data) {
//   if (error) {
//     return console.error(error);
//   }

//   console.log("try to access the file asynchronously " + data.toString());
// });
// console.log("after");

//synchronously
// console.log("before");
// const data = fs.readFileSync("file.txt");
// console.log("Data read in a synchronous manner " + data.toString());
// console.log("after");

// console.log("before");
// fs.appendFile(
//   "myFile.txt",
//   "New file create using asynchronously ",
//   function (error) {
//     if (error) {
//       console.error(error);
//     }
//     console.log("New file Created");
//   }
// );
// console.log("after");
//synchronously
// console.log("before");
// fs.appendFileSync(
//   "myFile.txt",
//   "New file create using synchronously ",
//   function (error) {
//     if (error) {
//       console.error(error);
//     }
//     console.log("New file Created");
//   }
// );
// console.log("after");

// console.log("before");
// fs.appendFileSync(
//   "myFile.html",
//   '<h1>New file create using synchronously </h1>',
//   function (error) {
//     if (error) {
//       console.error(error);
//     }
//     console.log("New file Created");
//   }
// );
// console.log("after");

//write file 
// fs.writeFile('file.txt','Heyy, i am replaced text asynchronously',function(error){
//     if(error){
//         console.error(error);
//     }
//     console.log("Data replaced !Saved");
// })
// fs.writeFileSync('file.txt','Heyy, i am replaced text synchronously',function(error){
//     if(error){
//         console.error(error);
//     }
//     console.log("Data replaced !Saved");
// })

//remove file

fs.unlink('myFile.html',function(err){
    if(err){
        console.error(err);
    }
    console.log("File deleted");
})
// fs.unlinkSync('myFile.html',function(err){
//     if(err){
//         console.error(err);
//     }
//     console.log("File deleted");
// })