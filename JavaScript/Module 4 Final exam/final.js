const def = () => {
    fetch('https://www.thecocktaildb.com/api/json/v1/1/search.php?f=a')
        .then(res => res.json())
        .then(data => {
            console.log(data);
            display(data.drinks);
        })
}
const handle_S = () => {
    const input = document.getElementById("int-field").value;
    document.getElementById("details_5").innerHTML = "";
    document.getElementById("all-foods").innerHTML = "";
    if (input) {
        fetch(`https://www.thecocktaildb.com/api/json/v1/1/search.php?s=${input}`)
            .then(res => res.json())
            .then(data => {
                display(data.drinks);
            })
            .catch(error => {
                const handle_error = document.getElementById("all-foods");
                handle_error.innerHTML = `
       <h3>Not Found</h3>
       `
            })
    }
    document.getElementById("int-field").value = "";
}
let display = (drinks) => {
    const drinks_container = document.getElementById("all-foods");
    drinks.forEach(drink => {
        const div = document.createElement("div");
        div.classList.add("single-div");
        div.innerHTML = `
        <img src="${drink.strDrinkThumb}" class="single-img">
        <h5>${drink.strDrink}</h5>
        <b><p>Category :</b> ${drink.strCategory}</p>
        <p>Instructions : ${drink.strInstructions.slice(0, 15)}...</p>
        <div class="sbd"><button class="sub-btn" onclick="add_Group('${drink.strDrinkThumb}',\`${drink.strDrink}\`)">Add To Group</button><button onclick="detail_5('${drink.strDrink}' , \`${drink.strAlcoholic}\`, \`${drink.strIngredient1}\`, \`${drink.strIngredient2}\`, \`${drink.strIngredient3}\`, \`${drink.strIngredient4}\`)" class ="sub-btn">Details</button></div>
        `
        drinks_container.appendChild(div);
    })
}
const detail_5 = (name, d1, d2, d3, d4, d5) => {
    const deFive = document.getElementById("details_5");
    // console.log(drink)
    const div = document.createElement("div");
    div.classList.add("single-div");
    div.innerHTML = `
    <h3>${name}</h3>
    <b><p>1. ${d1}<br>
    2. ${d2}<br>
    3. ${d3}<br>
    4. ${d4}<br>
    5. ${d5}<br>
    </p></b>
    `
    document.getElementById("details_5").innerHTML = "";
    deFive.appendChild(div);
}
let count = -1;

const add_Group = (image, name) => {
    count += 1;
    const CART = document.getElementById("add_cart");
    if (count > 7) {
        alert("!!You’ve reached the maximum allowed quantity!!")
    }
    else {
        const div = document.createElement("div");
        div.classList.add("cart_elements");
        div.innerHTML = `
        <h3 class="t1">${count} <h3> <img src="${image}" class="cart-img"> <h4> ${name}</h4>
        `

        CART.appendChild(div);
        btn();
    }

}
const vanish = () => {
    document.getElementById("details_5").innerHTML = "";
}
let bool = false;
const btn = () => {
    if (!bool) {
        const CART = document.getElementById("add_cart");
        CART.innerHTML = `
        <button class="remove-btn" onclick="remove()">Remove Cart</button>
        `
        bool = true;
    }
}
const remove = () => {
    document.getElementById("add_cart").innerHTML = "";
    count = 0;
    bool = false;
}
def();