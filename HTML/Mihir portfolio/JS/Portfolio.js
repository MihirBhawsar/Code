const text = document.querySelector(".line-1");
const textLoad = () => {
  setTimeout(() => {
    text.textContent = "Mihir Bhawsar";
  }, 0);
  setTimeout(() => {
    text.textContent = "Full Stack Developer";
  }, 5100);
  setTimeout(() => {
    text.textContent = "Mobile Developer";
  }, 9000); //1s = 1000 milliseconds
};
textLoad();
setInterval(textLoad, 14000);
let fUrl = "https://www.facebook.com/login/";
let IUrl = "https://www.instagram.com/accounts/login/";
let TUrl = "https://twitter.com/i/flow/login";
let GUrl = "https://github.com/MihirBhawsar";
let LUrl = "https://www.linkedin.com/feed/";
const facebook = document.querySelector(".facebook");
facebook.addEventListener("click", (e) => {
  window.open(fUrl, "_blank");
});
const twitter = document.querySelector(".twitter");
twitter.addEventListener("click", (e) => {
  window.open(TUrl, "_blank");
});
const github = document.querySelector(".github");
github.addEventListener("click", (e) => {
  window.open(GUrl, "_blank");
});
const linked = document.querySelector(".linked");
linked.addEventListener("click", (e) => {
  window.open(LUrl, "_blank");
});
const insta = document.querySelector(".insta");
insta.addEventListener("click", (e) => {
  window.open(IUrl, "_blank");
});
const dsa = document.querySelector(".dsa");
const backend = document.querySelector(".backend");
const frontend = document.querySelector(".frontend");
const mobileend = document.querySelector(".mobileend");

dsa.children[2].innerHTML = "60%";
dsa.children[1].style.strokeDasharray = "60";

backend.children[2].innerHTML = "50%";
backend.children[1].style.strokeDasharray = "50";
frontend.children[2].innerHTML = "70%";
frontend.children[1].style.strokeDasharray = "70";
mobileend.children[2].innerHTML = "80%";
mobileend.children[1].style.strokeDasharray = "80";

const mobileNumber = document.getElementsByClassName("mobileNumber");

var call = function () {
  var PhoneNumber = this.innerHTML;
  window.location.href = "tel://" + PhoneNumber;
};

Array.from(mobileNumber).forEach(function (element) {
  element.addEventListener("click", call);
});
let emailUrl = "https://mail.google.com/mail/?view=cm&fs=1&tf=1&to=";

const email = document.getElementsByClassName("email");

var setEmail = function () {
  var emailLink = emailUrl + this.innerHTML;
  window.open(emailLink, "Mailer");
};

Array.from(email).forEach(function (element) {
  element.addEventListener("click", setEmail);
});

const sendMailBtn = document.querySelector(".sendMailBtn");
// sendMailBtn.style.cursor="pointer";
sendMailBtn.addEventListener("click", (e) => {
  let nameInput = document.querySelector(".nameInput").value;
  let emailInput = document.querySelector(".emailInput").value;
  let subInput = document.querySelector(".subInput").value;
  let messageInput = document.querySelector(".messageInput").value;

  sendMail(nameInput, emailInput, subInput, messageInput);
});

function sendMail(name, email, subject, message) {
  let newSubject =
    "Name=" + name + "/n" + "Email=" + email + "Subject=" + subject;
  var link =
    "mailto:memihirbhawsar@gmail.com" +
    //  + "?cc=myCCaddress@example.com"
    "&subject=" +
    encodeURIComponent(newSubject) +
    "&body=" +
    encodeURIComponent(message);
  window.location.href = link;
}
