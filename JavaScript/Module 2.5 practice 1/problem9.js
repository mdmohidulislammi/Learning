const promt=require(`prompt-sync`)();
const monthly_savings=(array, liveCost)=>
{
    // console.log(array,liveCost);
    let sum=parseFloat(0);
    if(typeof array != "object")
        return "Invalid Input";
    else
    {
        for(let i=0;i<array.length;i++)
        if(array[i] >= 3000)
        {
            sum+=(parseFloat(array[i])- parseFloat((array[i]*20)/100))
        }
        else
        sum+=parseFloat(array[i]);
    }
    let savings =parseFloat(sum-liveCost);
    if(savings==0 || savings>0)
        return savings;
    else
    return "earn more";

}

const input=promt("");
let All_payments=input.split(" ").map(Number);
const living_cost=parseInt(promt());
const savings=monthly_savings(All_payments, living_cost);

console.log(savings);

