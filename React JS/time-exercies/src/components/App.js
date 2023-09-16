import React,{useState} from "react";


const App=()=> {
  const [currentTime,setCurrentTime]=useState(new Date().toLocaleTimeString());
  const updateTime=()=>{
    setCurrentTime(new Date().toLocaleTimeString());
  }
  setInterval(updateTime,1000);
  return (
    <div>
     <h1>{currentTime}</h1>
     <button onClick={updateTime}>update Time</button>
    </div>
  );
}

export default App;
