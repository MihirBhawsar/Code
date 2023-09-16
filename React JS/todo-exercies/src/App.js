import React,{useState} from 'react'
import Li from './components/Li';

const App=()=> {
  const [inputValue,setInputValue]=useState('');
  const [list,setList]=useState([]);

  const addTodoList=()=>{
    // let newArr=list; shallow Copy
    let newArr=[];
    for(let item of list){
      newArr.push(item);
    }
    newArr.push(inputValue);
    setList(newArr);
    setInputValue('');
    // setList([...list,inputValue]);


  }
  const updateInputValue=(event)=>{
    setInputValue(event.target.value);
  }
const deleteTodo=(idx)=>{
// const li=event.target
// li.parentNode.removeChildNode(li);

// list.slice(idx,1);
// setList([...list]);

// let newArr=[];
// for(let i in list){
//   if(idx!==i)
//      newArr.push(list[i]);
// }
// setList(newArr);

let newArr=list.filter((item,i)=>{
  return idx!==i;
});
setList(newArr);

}

  return (
    <div className='container'>
    <div className='heading'>
      <h1>TODO Application</h1>
    </div>
     <div className='form'>
      <input value={inputValue} onChange={updateInputValue}/>
      <button onClick={addTodoList}>Add</button>
     </div>
     <div>
      <ul>
          {list.map((item,idx)=>{
              return <Li deleteFunction={deleteTodo} key={idx} message={item} index={idx}/>;
          })}
      </ul>
     </div>
    </div>
  );
}

export default App;
