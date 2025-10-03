const prompt = require(`prompt-sync`)();

const Year = parseInt(prompt("Enter a valid year: "));

if ((Year % 4 == 0 && Year % 100 != 0) || Year%400 ==0)
    console.log("This is a Leap Year");
else 
console.log("Tihs is not a Leap Year");