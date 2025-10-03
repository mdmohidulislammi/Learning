// const target = document.getElementById("title");
// // console.log(target);
// target.style.color = "red";
// const allBox = document.getElementsByClassName("box");

// for (let i = 0; i < allBox.length; i++) {
//     const element = allBox[i];
//     element.style.backgroundColor = "green";
//     if (element.innerText == "box 5")
//     element.style.backgroundColor = "blue";
// }
// const target=document.getElementById("handle").addEventListener(
//     "click", (event)=> {
//         console.log("Hellow world");
//     }
// );

document.getElementById("handle").addEventListener("click", (event) => {
    const input_Val = document.getElementById("searchBox").value;
    // console.log(input_Val);

    const container = document.getElementById("comment-container");
    const p = document.createElement("p");

    p.classList.add("child")

    p.innerText = input_Val;
    container.appendChild(p);

    document.getElementById("searchBox").value = "";

    const all_comments = document.getElementsByClassName("child");
    // console.log(all_comments);
    for (const element of all_comments) {
        // console.log(element);
        element.addEventListener("click", (event) => {
            event.target.parentNode.removeChild(element);
        });
    }

});
fetch("https://jsonplaceholder.typicode.com/users")
    .then(res => res.json())
    .then(data => {
        displayData(data)
    })
    .catch((err) => {
        console.log(err);
    })
const displayData = (userData) => {
    const Container = document.getElementById("user_data_con");
    userData.forEach(user => {
        const div = document.createElement("div");
        div.classList.add("user");
        div.innerHTML = `
        
      <h4>Title</h4>
      <p>Description</p>
      <button>Details</button>
      
      `
    });
}
