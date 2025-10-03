var numbers = [1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10];
let num_set=new Set(numbers);
console.log(num_set);

let big=numbers[0];

for(let i=0;i<numbers.length;i++)
    if(big<numbers[i])
        big=numbers[i];

console.log(big);