function retryConnection(){

const status=document.getElementById("status")

if(navigator.onLine){
status.innerHTML="✅ Internet connected"
status.className="text-green-600 mt-4 font-semibold"
}
else{
status.innerHTML="❌ Still offline"
status.className="text-red-600 mt-4 font-semibold"
}
}