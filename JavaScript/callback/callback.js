// let add= (a)=>{

//     return a;
// };

// let min=(b)=>{

//     return b;
// };

// min(add(5));

// function mTocm(u){
//     return u*100;
// }

// function kgTog(u){
//     return u*1000;
// }

// function convert(fn,u){
//     return fn(u);
// }

// let gram=convert(kgTog,5);
// let cm=convert(mTocm,5);

//callback function

// function isOdd(ele) {
//   return ele % 2 != 0;
// }

// function filter(arr, fn) {
//   let ans = [];

//   arr.forEach((ele) => {
//     if (fn(ele)) {
//       ans.push(ele);
//     }
//   });
//   return ans;
// }

// let arr=[1,5,2,4,6,3,7,8,9];

// console.log(filter(arr,isOdd));

//anonymous function

// function filter(arr, callback) {
//   let ans = [];

//   arr.forEach((ele) => {
//     if (callback(ele)) {
//       ans.push(ele);
//     }
//   });
//   return ans;
// }
// let arr = [1, 5, 2, 4, 6, 3, 7, 8, 9];

// let oddVal = filter(arr, function (ele) {
//   return ele % 2 != 0;
// });

// console.log(oddVal);

//infinty loop

// let a=true;

// setTimeout(()=>{
// a=false;
// },1000);

// while(a){
// console.log("hello");
// }

// when multiple settimeout call
// setTimeout(() => {
//   console.log("fun1");
// }, 1000);
// setTimeout(() => {
//   console.log("fun2");
// }, 1000);
// setTimeout(() => {
//   console.log("fun3");
// }, 1000);

//task 1
console.log("start");

let a=true;
setInterval(function(){
  if(a){
    console.log("hello");
  }
},1000);

setTimeout(()=>{
  a=false;
},10500);

console.log("end");
