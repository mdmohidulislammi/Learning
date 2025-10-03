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
for (let i=0;i<phone.length;i++)
{
    // console.log(phone[i]);
    const elements=phone[i];
    if(elements.id==2)
        console.log(elements);
}
const result=phone.find(pd=>pd.id==3);//pd ==element
console.log(result)