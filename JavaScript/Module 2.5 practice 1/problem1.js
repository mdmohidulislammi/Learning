const prompt = require('prompt-sync')();
const marks=parseInt(prompt("Please type your number: "));

if(marks <= 100 && marks >= 80)
    console.log("Your Grade is 'A+'");
else if(marks < 80 && marks >=70)
    console.log("Your Grade is 'A'");
else if(marks < 70 && marks >=60)
    console.log("Your Grade is 'A-'");
else if(marks < 60 && marks >=50)
    console.log("Your Grade is 'B'");
else if(marks < 50 && marks >=40)
    console.log("Your Grade is 'C'");
else if (marks > 100)
    console.log("Your input in false.");
else
    console.log("Your Grade is 'F'");