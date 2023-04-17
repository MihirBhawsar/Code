class employee{
    constructor(name,mob){
        this.name=name;
        this.mob=mob;
    }

    getMember(){
        return this.name+this.mob;
    }
}


class student extends employee{
  
  constructor(name, roll, branch, mob) {
    super(name,mob);
    this.roll = roll;
    this.branch = branch;
  }

//   display(){
//     console.log(this.roll+(super(name)));
//   }
}

let me = new student("mihir", 54, "cs", 2546);
let rahul = new student("rahul", 24, "it", 9955);
let kunal = new student("kunal", 32, "me", 5645);
let hima = new student("hima", 45, "SE", 5566);
let ve = new student("vishal", 22, "EE", 2546);

// console.log(me);

console.log(me.getMember());
// rahul.display();

//Closure
function game(game){

    function score(goal){
        return game+" "+goal;
    }

    return score;
}
let score=game("football");
console.log(score(6));