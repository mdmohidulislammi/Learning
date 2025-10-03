const promt = require(`prompt-sync`)();
const n = promt("Enter how many input do you want to give: ");
const input = promt("");
let array = input.split(" ").map(Number);
let max_value = Number.MIN_SAFE_INTEGER;
for (let i = 0; i < array.length; i++)
    if (max_value <= array[i])
        max_value = array[i];
console.log(max_value);

