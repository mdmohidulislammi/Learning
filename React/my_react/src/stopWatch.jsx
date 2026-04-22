import React, {useState,useRef, useEffect} from 'react'
function Stopwatch(){
    const [isRunning,setIsRunning]=useState(false);
    const [elapsedTime, setElapsedTime]=useState(0);
    const intervalIdRef=useRef(null);
    const startTimeRef=useRef(0);

    useEffect(()=>
    {
        if (isRunning){
          intervalIdRef.current=  setInterval(()=>{
                setElapsedTime(Date.now()-startTimeRef.current);
            },10);
        }
        return ()=>{
            clearInterval(intervalIdRef.current)
        }

    },[isRunning])
    function start(){
     setIsRunning(true);
     startTimeRef.current=Date.now()-elapsedTime
    }
    function stop(){
     setIsRunning(false);
    }
    function reset(){
   setElapsedTime(0)
   setIsRunning(false);
    }
    function formatTime(){
        let h=Math.floor(elapsedTime/(1000*60*60))
        let min=Math.floor(elapsedTime/(1000*60)%60);
        let seconds=Math.floor(elapsedTime/1000 %60)
        h=String(h).padStart(2,"0")
        min=String(min).padStart(2,"0")
        seconds=String(seconds).padStart(2,"0")
       return `${h}:${min}:${seconds}`;
    }

    return (
        <div className='stopWatch'>
            <div className='display'> {formatTime()} </div>
            <div className='controls'>            
            <button onClick={start} className='start-btn' >Start</button>
            <button onClick={reset} className='reset-btn' >Reset</button>
            <button onClick={stop} className='stop-btn' >Stop</button>

            </div>

        </div>
    )
}
export default Stopwatch