//Promises

// let getData = () => {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve([
//         { fname: "Mihir", age: 25 },
//         { fname: "Rahul", age: 22 },
//       ]);
//     }, 1000);
//   });
// };

// function diplay(data){
//     console.log(data);
// }

// let promise=getData();
// console.log(promise);
// promise.then(data=>display(data));


//add function

// let add = (a, b) => {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       if (!isNaN(a) && !isNaN(b)) {
//         resolve(
//           a+b
//         );
//       } else {
//         reject("Please pass Number");
//       }
//     }, 1000);
//   });
// };

// function display(data){
//   console.log(data);
// }

// function errorFun(error){
//   console.log(error);
// }

// function finallycall(){
//   console.log("Promises is fulfilled or reject finally always call");
// }

// let promise=add(12,"hfg");
// console.log(promise);
// promise.then(display,errorFun);

// promise.catch(errorFun);

// promise.then(value=>console.log(value)).catch(error=>console.log(error)).finally(finallycall);

//promise all
// const promise1 = new Promise((resolve,reject)=>{
// setTimeout(() => {
//   resolve(3);
// }, 3000);
// });
// const promise2 = new Promise((resolve,reject)=>{
// setTimeout(() => {
//   // resolve(4);
//   reject("if one promise reject means all promise rejected.")
// }, 4000);
// });


// Promise.all([promise1,promise2]).then((result) => {
//   console.log(result[0]);
//   console.log(result[1]);
// }).catch((err) => {
//   console.log(err);
// });


//race=====================================

// const promise1 = new Promise((resolve,reject)=>{
// setTimeout(() => {
//   resolve(3);
// }, 3000);
// });
// const promise2 = new Promise((resolve,reject)=>{
// setTimeout(() => {
//   resolve(4);
//   // reject("if one promise reject means all promise rejected.")
// }, 4000);
// });


// Promise.race([promise1,promise2]).then((result) => {
//   console.log(result);
  
// }).catch((err) => {
//   console.log(err);
// });

//Allsettled

const promise1 = new Promise((resolve,reject)=>{
setTimeout(() => {
  resolve(3);
}, 3000);
});
const promise2 = new Promise((resolve,reject)=>{
setTimeout(() => {
  // resolve(4);
  reject("rejected.")
}, 4000);
});


Promise.allSettled([promise1,promise2]).then((result) => {
  console.log(result);
  
}).catch((err) => {
  console.log(err);
});