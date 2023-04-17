// (function name(lname){

//     console.log(lname);
//     // return lname;
// })("mihir");


// let sum=(function summ(a,b){
//     return a+b;
// })(5,12);
// console.log(sum);

// (()=>{
//     console.log("arrow function iife");
// })();

// console.log("iife called ");
//variable Shadowing 

// let vec="car";

// function vehicle(){
//     let vec="bike";
//     console.log(vec);
// }

// vehicle();
// console.log(vec);


//call--apply-bind

// let person1={
//     first:"mihir",
//     last:"bhawsar"
// };

// let person2={
//     first:"kunal",
//     last:"bhawsar"
// };


// let fullname=function(loc,car){
//     console.log(this.first+" "+this.last+" locatio="+loc+" "+car);
// }

// fullname.call(person1,"indore","BMV");
// fullname.call(person2,"mhow","ODD");

// fullname.apply(person2,["indore","BMV"]);
// fullname.apply(person2,["mhow","ODD"]);

// fullname.apply(person2,["indore","BMV"]);
// fullname.apply(person2,["mhow","ODD"]);

//bind
let user = {
    firstName: "John",
    sayHi() {
        console.log(`Hello, ${this.firstName}!`);
    }
  };

  let user2={
    firstName: "Mihir"
  }
  
  let sayHi = user.sayHi.bind(user2); // (*)
  
  // can run it without an object
  sayHi(); // Hello, John!
  
  setTimeout(sayHi, 1000); // Hello, John!
  
  // even if the value of user changes within 1 second
  // sayHi uses the pre-bound value which is reference to the old user object
  user = {
    sayHi() { alert("Another user in setTimeout!"); }
  };

  sayHi();