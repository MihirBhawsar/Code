let input = document.getElementById("inputTask");
console.log(input);

let submit = document.querySelector(".submit");
console.log(submit);

let msg = document.querySelector(".msg");

let list=[];

submit.addEventListener("click", (e) => {
  console.log("button clicked");

  if (input.value == "") {
    console.log("failure");
    msg.innerHTML = "Task Not be empty";
  } else {
    console.log("success");
    msg.innerHTML = "";
    addTask();
  }
});

let addTask = ()=>{
    list.push({
        "text": input.value,
    });

    console.log(list);
}