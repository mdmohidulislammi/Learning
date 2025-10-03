// alert()
// document.getElementsByTagName("h1") 
// const element=document.getElementById("2")
// element.style.color="red";
// const all_box=document.getElementsByClassName("box");
// console.log(all_box)
// for (let i=0;i<all_box.length;i++)
// {

//     const element=all_box[i]
//     element.style.backgroundColor="red"
//     if(element.innerText=="This is box 3")
//         element.style.backgroundColor="navy"
// }
document.getElementById("handle").addEventListener//-> element.addEventListener
    ("click", (event) => {
        // console.log("I'm a voch")
        const input_field = document.getElementById("int").value;
        // console.log(input_field)
        const cnt = document.getElementById("comment");
        const p = document.createElement("p");
        p.classList.add("child")
        p.innerText = input_field;
        cnt.appendChild(p);
        document.getElementById("int").value = "";
        const all_p_allElement = document.getElementsByClassName("child");
        for (const element of all_p_allElement) {
            element.addEventListener("click", (eve) => {
                eve.target.parentNode.removeChild(element);
            })
        }
    });
   fetch('https://jsonplaceholder.typicode.com/users')
      .then(response => response.json())
      .then(data => {
        // console.log(data);
        display(data);
      })
.catch((err)=>{
    console.log(err);
})
const display=(userData)=>{
const container=document.getElementById("user_container");
userData.forEach(element => {
    const div=document.createElement("div")
    div.classList.add("user");
    div.innerHTML=`
    <h4>title</h4>
<p>This is description</p>
<button>Details</button>
    `
    container.appendChild(div);
});
}