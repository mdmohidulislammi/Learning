// var name="mohidul Islam "
// var number=38473874
// console.log(name)
// console.log(number, name)
// console.log("this is my first javascript program")
// var num="12.5";
// var num1=15;
// console.log(num1 + parseFloat(num));
//if-else
let name = "mohidul"
let password = "MoHiDuL Islam "
if (name == password) {
    console.log("Wow this is right");
}
else
    console.log("Ohhh ho!")
if (false)
    console.log("ay hay , khoda jodi amake programming language banaito.")
// javascript if-else is like to c or c++ and conditional operators are same 
//object
var obj = {
    hand: 2,
    eye: 2,
    hair: "Not Balde",
    name: "Md. Mohidul Islam",
    father: { //nested object
        name: "none",
        age: "60+",
        passion: "none"
    }
}
console.log(obj)
console.log(obj.father.age)
console.log(obj.eye, obj.hair, obj.name)
console.log(Object.keys(obj))
//array is like c ,c++
var friends = ['tahsin', 'mohidul', 'muhidul', 'nasimul', 'dj baharul']
console.log(friends[0])
for (let i = 0; ; i++) {// infinite loop   // can use var instead of let
    if (i == 100) {
        console.log('yes',i)
        break
    }
}


//function
function sum(num1, num2){
    var result=num1+num2
    console.log(result)
    console.log("hello world , mohidul is a bad student.");
}
sum(12, 34)