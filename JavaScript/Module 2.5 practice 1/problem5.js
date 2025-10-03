const prompt=require(`prompt-sync`)();

const  fun =(arr)=>
{
    let div_th_fi=[];
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]% 3 ==0 || arr[i] % 5 ==0)
            div_th_fi.push(arr[i]);
    }
    return div_th_fi;
}

let array=[];
let n=parseInt(prompt("Enter how many input do you want to give: "));
for(let i=0;i<n;i++)
{
    let number=parseInt(prompt());
    array.push(number);
}

const result_array= fun(array);
console.log(result_array);