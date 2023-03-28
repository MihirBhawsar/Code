
let mark={
     weight:78,
     height:1.69,
};
let john={
     weight:92,
     height:1.95,
};
let mark2={
     weight:95,
     height:1.88,
};
let john2={
     weight:85,
     height:1.76,
};


function bmi( mass, height){
    let bmi=mass/(height*height);
    console.log(bmi);
}

bmi(mark.weight,mark.height);
bmi(john.weight,john.height);
bmi(mark2.weight,mark2.height);
bmi(john2.weight,john2.height);
