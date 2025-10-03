
const oddEven=(array)=>{
    let odd_number=[];
    let even_number=[];
    for(let i=0;i<array.length;i++)
    {
        if(array[i]%2==0)
            even_number.push(array[i]);
        else
        odd_number.push(array[i]);
    }
    return even_number;

}

const num=[1,2,3,4,35,23,5,4,33, 22,33, 66, 88, 6, 10, 8, 12];
const result=oddEven(num);
console.log(result);