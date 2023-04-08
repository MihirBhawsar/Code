let [hour, min, sec, mSec] = [0, 0, 0, 0];
let timerDisplay = document.querySelector(".timerDisplay");
let startTimer = document.getElementById("startTimer");
let pauseTimer = document.getElementById("pauseTimer");
let resetTimer = document.getElementById("resetTimer");
let time;
function runTimer() {
  mSec += 10;
  if (mSec >= 1000) {
    mSec = 0;
    sec++;
    if (sec >= 60) {
      sec = 0;
      min++;
      if (min >= 60) {
        min = 0;
        hour++;
      }
    }
  }

  let h = hour < 10 ? "0" + hour : hour;
  let m = min < 10 ? "0" + min : min;
  let s = sec < 10 ? "0" + sec : sec;
  let ms = mSec < 10 ? "00" + mSec : mSec < 100 ? "0" + mSec : mSec;

  timerDisplay.innerHTML = h + " : " + m + " : " + s + " : " + ms;
}

function watchStart() {
  if (time != null) {
    clearInterval(time);
  }
  time = setInterval(runTimer, 10);
}

function watchStop() {
  clearInterval(time);
}

function watchReset() {
    clearInterval(time);
  [hour, min, sec, mSec] = [0, 0, 0, 0];
  timerDisplay.innerHTML = "00 : 00 : 00 : 000";
}
startTimer.addEventListener("click", (e) => {
  watchStart();
});

pauseTimer.addEventListener("click", (e) => {
  watchStop();
});

resetTimer.addEventListener("click", (e) => {
  watchReset();
});
