// let bookListUI = document.getElementById("bookList");

// let books = [
//   {
//     title: "Money Man",
//     author: "mihir",
//     alreadyRead: false,
//   },
//   {
//     title: "DBMS",
//     author: "rahul",
//     alreadyRead: true,
//   },
//   {
//     title: "OOPS",
//     author: "C++",
//     alreadyRead: true,
//   },
//   {
//     title: "OS",
//     author: "mehta",
//     alreadyRead: true,
//   },
// ];

// books.forEach((element) => {
//   let text = `Title= ${element.title} and author is ${element.author} already read ${element.alreadyRead}`;
//   let newLI = document.createElement("p");
//   newLI.textContent = text;
//   bookList.appendChild(newLI);
// });

let contner = document.querySelector(".contner");
let listItem = document.querySelector(".listItem");
let nick = document.getElementById("nick");
let fav = document.getElementById("fav");
let home = document.getElementById("home");

contner.style.fontFamily = "Arial, Helvetica, sans-serif";
listItem.style.color = "red";

nick.textContent = "Montu";
fav.textContent = "Ash";
home.textContent = "Pithampur";
let div1=document.createElement("div");
div1.className="dynamicDiv";
let img = document.createElement("img");
let p = document.createElement("p");
p.innerHTML="dynamic value add";
img.style.width = "300px";
img.style.height = "300px";
img.src = "https://picsum.photos/200/301";
div1.style.color="white";
div1.appendChild(p);
div1.appendChild(img);
contner.appendChild(div1);
