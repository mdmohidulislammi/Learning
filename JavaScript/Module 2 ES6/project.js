// alert();
const allProd=()=>{
    fetch('https://fakestoreapi.com/products')
.then(response => response.json())
.then((data)=> {
// console.log(data);
display(data);
});
};
const display=(products)=>{
    const prod_cnt=document.getElementById("product");
    products.forEach(product=>{
        const div=document.createElement("div")
        div.classList.add("card")
        div.innerHTML=`
        <img class="card-img" src=${product.image} alt="image-1">
        <h5>Name : ${product.title}</h5>
        <p>Price : ${product.price} $</p>
        <button onclick="addToCart('${product.title}',' ${product.price}')">Add to Cart</button>
        `
        prod_cnt.appendChild(div);
    })
}
const addToCart=(name, price)=>{
    // console.log(name, price)
    const cnt=document.getElementById("cart-sub")
    const div=document.createElement("div")
    div.classList.add("cart-info")
    div.innerHTML=`
    <p>${name}</p>
    <h3 class="price">${price} $</h3>
    
    `
    cnt.appendChild(div);
    update_total();

}
const update_total=()=>
{
    const allPrice=document.getElementsByClassName("price");
    let count=0;
    for (const element of allPrice)
    {
         count+=parseFloat(element.innerText);
    }
    document.getElementById("total").innerText=count.toFixed(2);
}










allProd();