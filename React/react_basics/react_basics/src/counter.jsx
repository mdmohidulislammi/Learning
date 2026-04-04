import React , {useState} from 'react';
function Counter(){
const [count, setCount]=useState(0)
const incr=()=>{
    setCount(count+1);
}
const decr=()=>{
    setCount(count-1);
}
const reset=()=>{
   setCount(0);
}
return (

    <div className='counter-container'>
    <p className='count-display'>
        {count}
    </p>
    <button className='counter-btn' onClick={decr}>Decrement</button>
    <button className='counter-btn' onClick={incr}>Increment</button>
    <button className='counter-btn' onClick={reset}>Reset</button>
    </div>
);
}
export default Counter