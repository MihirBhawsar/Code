let arr = [1, 2, 3, -4, 5, -6, 7, -8, 9];


//map and filter

// let mapArr=arr.map(item=>item*2);
// console.log(mapArr);

// let filterArr=arr.filter(item=>item%2===0);
// console.log(filterArr);

//poilyfill for map and filter

// Array.prototype.myMap= function(callback) {
//   let mapArr = [];
//   for (let i = 0; i < this.length; i++) {
//     mapArr.push(callback(arr[i]));
//   }
//   return mapArr;
// }

// function mul(val){
//     return val*2;
// }
// let newArr =arr.myMap(mul);
// console.log(newArr);

// function even(x) {
//   return x % 2 == 0;
// }

// Array.prototype.myFilter = function (cb) {
//   let newArr = [];
//   for (let i = 0; i < arr.length; i++) {
//     if (cb(arr[i])) {
//       newArr.push(arr[i]);
//     }
//   }
//   return newArr
// };

// let newArr = arr.myFilter(even);
// console.log(newArr);


//reduce
function sumEle(accumulator, currentValue){
    return accumulator+ currentValue;
}
// let sum=arr.reduce(sumEle);
// console.log(sum);


let posArr=arr.filter(item =>item>0).reduce(sumEle);
// let sumPos=posArr.reduce(sumEle);
console.log(posArr);