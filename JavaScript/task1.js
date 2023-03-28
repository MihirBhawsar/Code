// let msg = document.querySelector(".msg");

// let submit = document.querySelector(".submit");
// let count = 1;
// let oldmsg = msg.textContent;
// submit.addEventListener("click", (e) => {
//   msg.innerHTML = `${oldmsg}` + "Bhawsar" + count++;
//   submit.innerHTML = "Clicked";
// });

// let task2btn = document.getElementById("task2btn");

// let tasklist = document.getElementsByClassName("item");
// console.log(tasklist);

// task2btn.addEventListener("click", () => {
//     tasklist[2].innerHTML = `Item changed`;
// });

let newtext = document.getElementById('inputText');

let add = document.getElementById('add');
let show = document.getElementById('show');
let task1 = document.getElementsByClassName('task1');
console.log(task1);
let list = [];
add.addEventListener("click", (e) => {
    addTask();
    newtext.value="";
});
show.addEventListener("click", (e) => {
 console.log(list);
 for(let i=0; i<list.length; i++){
    console.log(list[i].text);
    task1[i].textContent=list[i].text;
}
createList();
});

let addTask = ()=>{
    list.push({
        "text": newtext.value,
    });

   
}

let div1=document.querySelector('.div1');
let square=true;

div1.addEventListener("click",(e)=>{
if(square){
    div1.style.borderRadius="50%";
    div1.style.backgroundColor="red";
    square=false;
}else{
    div1.style.borderRadius="0%";
    div1.style.backgroundColor="white";

    square=true;
}
});


let fruti=["apple","mango","banana"];

let frutiList=document.getElementById('frutiList');

// fruti.forEach(ele => {

//     let itemEle=document.createElement("li");
//     itemEle.textContent=ele;
//     frutiList.appendChild(itemEle);
    
// });

let createList=()=>{
list.forEach(ele => {
    let itemEle=document.createElement("li");
        itemEle.textContent=ele.text;
        frutiList.appendChild(itemEle);
    
});
};