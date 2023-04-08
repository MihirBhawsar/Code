const suffer = document.querySelector(".suffer");
const diceImg = document.querySelector(".diceImg");

suffer.addEventListener("click", (e) => {
  let x = Math.floor(Math.random() * 6 + 1);
  console.log(x); 
  diceImg.classList.remove('diceImg'); // reset animation
  void diceImg.offsetWidth; // trigger reflow
  diceImg.classList.add('diceImg'); // start animation
  var delayInMilliseconds = 1000; //1 second

setTimeout(function() {
  //your code to be executed after 1 second

  switch (x) {
    case 1:
      diceImg.src = "./IMage/dice1.png";
      break;
    case 2:
      diceImg.src = "./IMage/dice2.png";
      break;
    case 3:
      diceImg.src = "./IMage/dice3.png";
      break;
    case 4:
      diceImg.src = "./IMage/dice4.png";
      break;
    case 5:
      diceImg.src = "./IMage/dice5.png";
      break;
    case 6:
      diceImg.src = "./IMage/dice6.png";
      break;
    default:
      diceImg.src = "./IMage/dice1.png";
  }
}, delayInMilliseconds);
});
