const fun=(array=[])=>
{
     let name=array[0];
     for(let i=0;i<array.length;i++)
        if(name.length<array[i].length)
            name=array[i];
    return name;
}

var friends = ["rahim", "karim", "abdul", "sadsd", "heroAlom"];
const big_name=fun(friends);
console.log(big_name);