
const big_name=(array=[])=>{
    let biggest_name=array[0];
    for(let i=0;i<array.length;i++)
    {    if(biggest_name.length< array[i].length)
            biggest_name=array[i];}
    return biggest_name;
}

const friends=["Rafiq", "Kalam", "Jabbar", "Salam", "Barkat", "My country is Bangladesh"];
const result=big_name(friends);
console.log(result);
alert();