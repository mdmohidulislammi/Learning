
const search_butt = (event) => {
    const input = document.getElementById("search-bar").value;
    if (!input) return;
    fetch(`https://www.themealdb.com/api/json/v1/1/search.php?s=${input}`)
        .then(res => res.json())
        .then(data => {
            document.getElementById("show-foods").innerHTML = "";
            display(data.meals || []);
        });

    document.getElementById("search-bar").value = "";
    // console.log(input);
}

const display = (foods) => {
    const container = document.getElementById("show-foods");
    foods.forEach(food => {
        console.log(food);
        const div = document.createElement("div");
        div.classList.add("food");
        const str = food.strInstructions;
        div.innerHTML = `
        <img class="food-img" onclick="eachFood('${food.strMealThumb}', \`${food.strMeal}\`, \`${str}\`)" src="${food.strMealThumb}"/>
        <h4 onclick="eachFood('${food.strMealThumb}', \`${food.strMeal}\`, \`${str}\`)">${food.strMeal}</h4>
        <button type="button" class="btn btn-sm btn-primary" data-bs-toggle="popover" data-bs-title="Instructions" data-bs-content="${str}">Instructions</button>
        `
        container.appendChild(div);
    });
    const popoverInstr = [].slice.call(document.querySelectorAll('[data-bs-toggle="popover"]'));
    popoverInstr.forEach(press => {
        new bootstrap.Popover(press);

    })
}

const eachFood = (image, name, instr) => {
    const single = document.getElementById("single-food");
    single.innerHTML = "";
    const singleCont = document.createElement("div");
    singleCont.classList.add("single-cont");
    singleCont.innerHTML = `
     <img class="food-img" src="${image}"/>
        <h4>${name}</h4>
        <button type="button" class="btn btn-sm btn-primary" data-bs-toggle="popover" data-bs-title="Instructions" data-bs-content="${instr}">Instructions</button>
    `

    single.appendChild(singleCont);
    new bootstrap.Popover(singleCont.querySelector('[data-bs-toggle="popover"]'));
}