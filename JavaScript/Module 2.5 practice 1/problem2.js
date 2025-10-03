const prompt= require(`prompt-sync`)();

const Number = parseInt(prompt("Please input your number: "));
if(Number%2==0)
    console.log("This is an Even Number.");
else
    console.log("This is an Odd Number.")