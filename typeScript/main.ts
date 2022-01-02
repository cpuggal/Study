export {}

let message = "Hello Chandan...!";
console.log(message);

let name: string = 'Chandan'
let lang: string = "typescript"
let num: number = 100;

let sentence: string = `Hey, my name is ${name}
and I am learning ${lang}`

console.log(sentence);

console.log("first char is " + name[1]);

//num.toPrecision(1);

let myname:string = null;


let myArray: Array<number> = [1,2,3,4];
console.log("array is : " + myArray);

let mytupple: [String, number] = ['Chandan', 1987]
console.log("name : " + mytupple[0] + ", YOB : " + mytupple[1]);

var random: any = "Vedansh";
console.log((random as string).toUpperCase());
console.log(random.toUpperCase());
//console.log(random.name);

let newRandom: unknown = "Puggal"
console.log("Surname is " + newRandom);

newRandom = 10;
console.log((newRandom as number).toPrecision(10))
//onewRandom.