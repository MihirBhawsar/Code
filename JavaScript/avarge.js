// function avg(point1, point2, point3) {
//   let avg = (point1 + point2 + point3) / 3;
//   return avg;
// }

// function winner(dolphinAvg, dolphinAvg) {
//   if (dolphinAvg > koakasAvg && dolphinAvg > 100) {
//     console.log("Dolphins win");
//   } else if (dolphinAvg < koakasAvg && koakasAvg > 100) {
//     console.log("koakas win");
//   } else if (dolphinAvg == koakasAvg && dolphinAvg > 100) {
//     console.log("draw");
//   } else {
//     console.log("NO wins");
//   }
// }

// let Dolphins = {
//   point1: 96,
//   point2: 108,
//   point3: 89,
// };
// let Koakas = {
//   point1: 88,
//   point2: 91,
//   point3: 110,
// };
// let dolphinAvg = avg(Dolphins.point1, Dolphins.point2, Dolphins.point3);
// let koakasAvg = avg(Koakas.point1, Koakas.point2, Koakas.point3);

// winner(dolphinAvg, koakasAvg);

//Grade

let mihir = {
  c: 85,
  p: 85,
  m: 85,
  h: 85,
  e: 85,
};

function percentage() {
  let per = ((c + p + m + h + e) / 500) * 100;
  return per;
}

let mihirPer = percentage(mihir.c, mihir.p, mihir.m, mihir.h, mihir.e);

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
