let buttons = document.getElementsByTagName("button");
let displayValue = document.querySelector(".displayValue");
let stringValue="";
console.log(buttons);
Array.from(buttons).forEach((button) => {
  button.addEventListener("click", (e) => {
    if (button.value == "=") {
        try{

       
        stringValue=eval(stringValue);
        displayValue.innerHTML=stringValue;
    }catch(err){
        stringValue="Error";
        displayValue.innerHTML=stringValue;
        stringValue="";
    }

    } else if (button.value == "clear") {
        stringValue="0";
        displayValue.innerHTML=stringValue;
        stringValue="";
    } else if (button.value == "pos-neg") {
        displayValue.innerHTML=stringValue;

    } else {
        stringValue+=button.value;
        displayValue.innerHTML=stringValue;
        console.log(stringValue);

    }
  });
});
