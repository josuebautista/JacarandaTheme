class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }

    /**
     * Say hello to the person
     */
    sayHello() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
    }

    static greet(name) {
        console.log(`Hello, ${name}!`);
    }
}

const person1 = new Person("John", 25);
const person2 = new Person("Jane", 30);

person1.sayHello();
person2.sayHello();

Person.greet("Alice");
Person.greet("Bob");
