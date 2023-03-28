const open = document.querySelector('.open');
console.log(open);

const close=document.querySelector('.close');
console.log(close);

const modelDiv=document.querySelector('.modelDiv');
console.log(modelDiv);

open.addEventListener('click',(e)=>{
    modelDiv.style.display='flex';
});
close.addEventListener('click',(e)=>{
    modelDiv.style.display='none';
});