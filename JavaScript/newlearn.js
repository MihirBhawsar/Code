let cTOf = function (c) {
  let f = c * (9 / 5) + 32;
  return f;
};

console.log(cTOf(35));

let AreaR = function (l, b) {
  let a = l * b;
  return a;
};

console.log(AreaR(18, 50));

let circleArea = function (r) {
  let area = (22 / 7) * r;
  return area;
};
console.log(circleArea(12));

let circlePre = function (r) {
  let pre = 2 * (22 / 7) * r;
  return pre;
};
console.log(circlePre(12));

let equal = function (a, b) {
  if (a == b) {
    return "no. is equal";
  } else {
    return "no. is not equal";
  }
};

console.log(equal(5, 4));

let largestThree = (a, b, c) => {
  if (a > b && a > c) {
    return a;
  } else if (b > a && b > c) {
    return b;
  } else {
    return c;
  }
};

console.log(largestThree(45, 85, 69));

let evenOrOdd = (a) => {
  if (a % 2 == 0) {
    return "even";
  } else {
    return "odd";
  }
};

console.log(evenOrOdd(10));

let square = (a) => {
  return a * a;
};

console.log(square(23));

let range = (f, e, t) => {
  let i;
  for (i = f; i < e; i++) {
    if (i == t) {
      return "present";
    }
  }
  if (i == e) {
    return "not present";
  }
};

console.log(range(1, 11, 15));

let greet = (name) => {
  return `Hellow ${name} ,However you`;
};

console.log(greet("Mihir"));

let counter = (a) => {
  if (a > 100) {
    a = 0;
  } else {
    a++;
  }
  return a;
};

let counterExp = function (a) {
  if (a > 100) {
    a = 0;
  } else {
    a++;
  }
  return a;
};

console.log(counter(5));
console.log(counterExp(50));

let avg = (p1, p2, p3) => {
  return (p1 + p2 + p3) / 3;
};
let dAvg = avg(12, 89, 36);
let kAvg = avg(89, 85, 96);
let whoWin = (d, k) => {
  if (d > k && d > 2 * K) {
    console.log("D win");
  } else if (d < k && k > 2 * d) {
    console.log("k Win");
  } else {
    console.log("No win");
  }
};
whoWin(dAvg, kAvg);

let fullName = (first, last) => {
  return `Your FullName is ${first}-${last}`;
};

console.log(fullName("Mihir", "BHawsar"));

let KgToLBS = (kg) => {
  return kg * 2.2;
};
let kg = 10;
console.log(`${kg} equal to - ${KgToLBS(kg)}LBS`);

let fit = (lbs) => {
  if (lbs > 150) {
    return "obese";
  } else if (las > 100 && lbs < 150) {
    return "you are ok";
  } else if (lbs < 100) {
    return "underWeight ";
  }
};

let isEven = (x)=> (x%2==0)

let x=10;

console.log(`this value is even ${x} -- ${isEven(x)}`);


const array=["mihir","kunal","chetna","malay"]
console.log(array);

//mixed
const mixedData=["name",42,true,2.1]
console.log(mixedData);