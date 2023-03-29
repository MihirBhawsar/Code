let btn=document.getElementsByClassName('btn');
let decs=document.getElementsByClassName('decs');


btn[0].addEventListener("click",(e)=>{

    if(btn[0].innerText=='+'){
        decs[0].style.display="block";
        btn[0].innerText='-';
    }else{
        decs[0].style.display="none";
        btn[0].innerText='+';
    }


});
btn[1].addEventListener("click",(e)=>{

    if(btn[1].innerText=='+'){
        decs[1].style.display="block";
        btn[1].innerText='-';
    }else{
        decs[1].style.display="none";
        btn[1].innerText='+';
    }


});