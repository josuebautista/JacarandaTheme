class EntityPerson {
    name: string;
    age: number;

    constructor(name: string, age: number) {
        this.name = name;
        this.age = age;
    }
    /**
     * Say hello to the Entityperson
     */
    sayHello() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
    }

    static greet(name: string) {
        console.log(`Hello, ${name}!`);
    }
}

const p1 = new EntityPerson("John", 25);
const p2 = new EntityPerson("Jane", 30);

p1.sayHello();
p2.sayHello();

Person.greet("Alice");
