const phone=[
    {id:1, name:"xiomi", brand:"Redmi", color:"red"},
    {id:2, name:"samsung", brand:"Samsung S21", color:"white"},
    {id:3, name:"Iphone", brand:"Iphone234", color:"yellow"},
    {id:4, name:"Poco", brand:"Redmi", color:"red"},
    {id:5, name:"xiomi", brand:"Redmi", color:"blue"},
    {id:6, name:"Nokia", brand:"Redmi", color:"purple"},
    {id:7, name:"Walton", brand:"Walton", color:"Gray"},
    {id:8, name:"Redmi", brand:"Redmi", color:"red"},
];

const result=phone.filter(product=> product.color=="red");
console.log(result);