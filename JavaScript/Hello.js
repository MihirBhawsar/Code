// var hello='hello';
// var hello_world='world';
// var helloWorld="helloWorld"
// // var hello w ='mihir';
// // var 1hello='mihir';
// var _1 ='mihir';
// console.log(hello+" "+hello_world+" "+helloWorld+" "+_1);

// let value;
// console.log(typeof value);
// // variable are contener , we use to store value.
// // we need variable to perform operation .
// // we declafre variable using var let const .

// let language,isIsland,population,country;
// isIsland=false;
// language='Hindi';
// population=10000;
// country='india';

// console.log("country-"+country+"--typeof-" +typeof country) ;
// console.log("isIsland-"+isIsland+"--typeof-" +typeof isIsland);
// console.log("language-"+language+"--typeof-" +typeof language);
// console.log("population-"+population+"--typeof-" +typeof population);

// let myvari;
// console.log("myvari-"+myvari+"--typeof-" +typeof myvari) ;

// let nulll=null;
// console.log("nulll-"+nulll+"--typeof-" +typeof nulll) ;

// let mydata={

//     first:"mihir",
//     last:"bhawsar",
//     age:25,
//      eyeColor:"blue"

// };
// console.log(mydata) ;
// console.log(mydata.eyeColor) ;

// var fname="mihir";

// function lnameFun(){
//     var lname="bhawsar";
//     console.log(lname);
// }

// console.log(fname);
// // console.log(lname);
// lnameFun();

// var fname="kunal";
// console.log(fname);

// fname="mihirbhawsAR";
// console.log(fname);

// let count=4;

// if(count>3)
// {
//     let value="value is GRT 3"
//     console.log('value :>> ', value);
// }

// // console.log(value);
// console.log(count);

// //let update value but not redeclary
// // let count=5;

// count=2;
// console.log(count);

// const i=2,m=2;
//  console.log(i==m);
//  console.log(i!=m);
//  console.log(i===m);
//  console.log(i==='2');

//  const x=7,y=6;

//  console.log((x>5)&&(y<6));
//  console.log((x>5)||(y<6));

// function add(a,b){
//     return a+b;
//     // console.log(a+b);
// }

// console.log(add(11,74));

//lagest
function largest(a, b, c) {
  if (a > b && a > c) {
    return a;
  } else if (a < b && b > c) {
    return b;
  } else if (a < c && b < c) {
    return c;
  }
}

console.log(largest(12, 45, 78));

function evenOrOdd(a) {
  if (a % 2 == 0) {
    return "even";
  } else {
    return "false";
  }
}

console.log(evenOrOdd(10));

function square(a) {
  return a * a;
}

console.log(square(5));

function range(f, e, t) {
  let i;
  for (i = f; i < e; i++) {
    if (i == t) {
      return "present";
    }
  }
  if (i == e) {
    return "not present";
  }
}

console.log(range(1, 11, 15));

function percentage(c, p, m, h, e) {
  let per = ((c + p + m + h + e) / 500) * 100;
  return per;
}

function grade(per) {
  if (per >= 90) {
    console.log("Grade A");
  } else if (per >= 80) {
    console.log("Grade B");
  } else if (per >= 70) {
    console.log("Grade c");
  } else if (per >= 60) {
    console.log("Grade d");
  } else if (per >= 40) {
    console.log("Grade e");
  } else if (per < 40) {
    console.log("Grade f");
  }
}

grade(percentage(85, 86, 81, 91, 89));

function equal(a, b) {
  if (a == b) {
    return "no. is equal";
  } else {
    return "no. is not equal";
  }
}

console.log(equal(5, 4));

function cTOf(c) {
  let f = c * (9 / 5) + 32;
  return f;
}

console.log(cTOf(35));

function AreaR(l, b) {
  let a = l * b;
  return a;
}

console.log(AreaR(18, 50));

function circleArea(r) {
  let area = (22 / 7) * r;
  return area;
}
console.log(circleArea(12));
function circlePre(r) {
  let pre = 2 * (22 / 7) * r;
  return pre;
}
console.log(circlePre(12));
