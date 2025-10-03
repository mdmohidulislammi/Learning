
const displayProduct=(products)=>{
    const productContainer=document.getElementById("product-container");
       products.forEach(product => {
        const div=document.createElement("div");
        div.classList.add("card");
        div.innerHTML=`
        <img class="image" src="${product.image}" alt="">
        <h5>${product.title}</h5>
        <h3>Price :  ${product.price} $</h3>
        <p>${product.description}</p>
        <button>Details</button>
        <button onclick="handle_Cart('${product.title}',${product.price})">Add to Cart</button>

        
        `
        productContainer.appendChild(div)
    });
}
const AllProducts=()=>{
    fetch('https://fakestoreapi.com/products')
  .then(response => response.json())
  .then(data =>
    { 
        displayProduct(data)
    });
}

const handle_Cart=(name, price)=>{
    const cart_no=document.getElementById("cartCount").innerText;
    let No=parseInt(cart_no);
    No+=1;
    document.getElementById("cartCount").innerText=No;

const contain=document.getElementById("cart-main-cont");
const div=document.createElement("div");
div.classList.add("cart-info");
div.innerHTML=`
<p>${name} </p>
<h3 class="price">${price} $ </h3>

`
contain.appendChild(div);
update_total();

}

const update_total=()=>
{
 const   allPrice= document.getElementsByClassName("price");
 let sum=0;
 for(const element of allPrice)
 {
    sum+=parseFloat(element.innerText);
 }
 document.getElementById("Total").innerText=sum.toFixed(2);
}
AllProducts();