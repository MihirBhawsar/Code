import React ,{useState}from 'react';
//functional component 
// import '../stylesheets/style.css'
import Form from './Form';
const App=()=>{
    const styles={
        color: 'blue',
		backgroundColor: 'gray'
    }
    const [count,setCount]=useState(0);
    const h1ClickHandler=()=>{
        alert('clicked');
    };

    function greet(name){
        alert(`Hello ${name}`);
    }

   const plusOne=()=>{
        setCount(count+1);
    
    }
    const minusOne=()=>{
        setCount(count-1);

    }
    const resetCount=()=>{
        setCount(0);
    }
    return (
    <React.Fragment>
        <h1 style={styles}>hello</h1>
        <h1 style={{color:'red'}} onClick={h1ClickHandler}>hello</h1>
        <p>world</p>
        {/* <h1>you clicked button {count} times</h1>
        <button onClick={plusOne}>+1</button>
        <button onClick={resetCount}>reset</button>
        <button onClick={minusOne}>-1</button> */}
        <Form greetFunction={greet} method="post" action="/products" inputType="number" />
        <Form greetFunction={greet} method="get" action="/login" inputType="password" />
        <Form  greetFunction={greet} method="post" action="/search" inputType="text" />
    </React.Fragment>
    );
};

//class based component
// class App extends React.Component{
//     render(){
//         return(
//             <React.Fragment>
//                 <h1>Hello</h1>
//                 <p>world</p>
//             </React.Fragment>
//         );
//     }
// }
export default App;