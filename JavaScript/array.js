// const mixed=[123,20.5,'mihir',true];

// console.log(mixed[0]);
// console.log(mixed[1]);
// console.log(mixed[2]);
// console.log(mixed[3]);

// const objArray=[
// {name:'mihir'},
// [15,45,35],
// function name(name){
//     console.log(name);
// },

// ]

// console.log(objArray);
// console.log(objArray[2]("mihir"));

// let word=["I","am",]

// console.log(word);
// word.push('Mihir');
// console.log(word);

// word.unshift('hey');
// console.log(word);

// word[0]='hello'
// console.log(word);

// console.log(word.length)

// let removeLast=word.pop();
// console.log(removeLast);
// console.log(word);

// let removeFirst=word.shift();
// console.log(removeFirst);
// console.log(word);
// console.log(word.length)

// const arr1 = ["Cecilie", "Lone"];
// const arr2 = ["Emil", "Tobias", "Linus"];
// const arr3 = ["Robin"];
// const children = arr1.concat(arr2, arr3);

// console.log(children);

//-----------BMI-------------------

let Marks = {
  name: "Mark",
  height: 1.69,
  weight: 78,
};
let John = {
  name: "John",
  height: 1.95,
  weight: 92,
};

let calcBMI = (weight, height) => weight / (height * height);

let bmiMarks = calcBMI(Marks.weight, Marks.height);
let bmiJohn = calcBMI(John.weight, John.height);

if (bmiMarks > bmiJohn) {
  console.log(
    `${Marks.name}'s BMI (${bmiMarks}) is higher then ${John.name} (${bmiJohn})`
  );
} else {
  console.log(
    `${John.name}'s BMI (${bmiJohn}) is higher then ${Marks.name} (${bmiMarks})`
  );
}

let bills = [125, 555, 44];
let tips = [];
let total = [];

// function calcTip(billValue) {
//   if (billValue > 50 && billValue < 300) {
//     return (billValue * 15) / 100;
//   } else {
//     return (billValue * 20) / 100;
//   }
// }
let calcTip = (billValue) =>
  billValue > 50 && billValue < 300
    ? (billValue * 15) / 100
    : (billValue * 20) / 100;

for (let i = 0; i < bills.length; i++) {
  tips.push(calcTip(bills[i]));
  total.push(tips[i] + bills[i]);
}
for (let i = 0; i < bills.length; i++) {
  console.log(`Bill= ${bills[i]}-- Tips=${tips[i]} --- Total=${total[i]}`);
}

let billValue = 275;
console.log(
  `the bill was ${billValue} ,the tip was ${calcTip(
    billValue
  )}, and the total value is ${billValue + calcTip(billValue)}`
);

for (let index = 0; index < 10; index++) {
  console.log("mihir");
}
for (let index = 0; index < 10; index++) {
  console.log(5 * (index + 1));
}
for (let index = 0; index < 10; index++) {
  console.log(7 * (index + 1));
}
