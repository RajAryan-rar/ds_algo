/*
//QS
class Complex {
    real : number;
    imag : number;

    constructor(real : number, imag : number) {
        this.real = real;
        this.imag = imag;
    }

    display(): void {
        console.log(`${this.real} + ${this.imag}i`);
    }

    add(c1:Complex): void {
        this.real += c1.real;
        this.imag += c1.imag;
    }

    multiply(c1:Complex): void {
        let x = this.real, y = this.imag;
        this.real = x*c1.real - y*c1.imag;
        this.imag = x*c1.imag + y*c1.real;
    }
}

let c1 = new Complex(2,3);
let c2 = new Complex(1,3);

c1.display();
c2.display();

c1.multiply(c2);
c1.display();
*/



//Generics in function implementation
/*
function linearSearch<T>(arr: T[], target: T): [number,T] {
    for(let i=0; i<arr.length; i++) {
        if(arr[i] == target) return [i,arr[i]];
    }
    return [-1,target];
}

const arr: number[] = [1,2,5,1,2,3,8];
console.log(linearSearch<number>(arr,5));

const arr2: string[] = ["abc", "def", "ghi", "jkl"];
console.log(linearSearch<string>(arr2, "jkl"));
*/


//Generics in classes, implementation :-
//  --Stack implementation
/*
class Stack<T> {
    private array: T[];

    constructor() {
        this.array = [];
    }

    push(ele:T): void {
        this.array.push(ele);
    }
    pop(): void {
        this.array.pop();
    }
    top(): T {
        return this.array[this.array.length - 1];
    }
    display() : void {
        console.log(this.array);
    }

}

let st = new Stack<number>();
st.push(2);
st.push(5);
st.push(9);
st.push(6);

console.log(st.top());
st.pop();
console.log(st.top());

st.display();
*/


//  --LinkedList implementation
/*class Person {
    private name: string;
    private age : number;
    constructor(name:string, age:number) {
        this.name = name;
        this.age = age;
    }
}

class node<T> {
    data : T;
    next : node<T> | null;

    constructor(data:T) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList<T> {
    head: node<T> | null;

    constructor() {
        this.head = null;
    }

    display(): void {
        let temp : node<T> | null = this.head;
        while(temp != null) {
            console.log(temp.data);
            temp = temp.next;
        }
    }

    addAtTail(x: T): void {
        let newNode = new node(x);

        if(this.head == null) {
            this.head = newNode;
            return;
        }

        let temp : node<T> | null = this.head;
        while(temp != null && temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }
}

let ll = new LinkedList<string>();
ll.addAtTail('a');
ll.addAtTail('b');
ll.addAtTail('c');
ll.addAtTail('d');
ll.addAtTail('e');
ll.display();


let ll2 = new LinkedList<number>();

ll2.addAtTail(1);
ll2.addAtTail(2);
ll2.addAtTail(3);
ll2.addAtTail(4);
ll2.addAtTail(5);

ll2.display();


let ll3 = new LinkedList<any>();
ll3.addAtTail('a');
ll3.addAtTail(1);
ll3.addAtTail('b');
ll3.addAtTail(2);
ll3.addAtTail('c');
ll3.display();


let ll4 = new LinkedList<Person>();
ll4.addAtTail(new Person("Raj", 22));
ll4.addAtTail(new Person("Manas", 20));
ll4.addAtTail(new Person("Rudraksh", 20));
ll4.addAtTail(new Person("Vipul", 21));
ll4.addAtTail(new Person("Rahul", 21));
ll4.addAtTail(new Person("Mahi", 20));
ll4.addAtTail(new Person("Aakhya", 20));

ll4.display();
*/


//Generics in interface, implementation :-
/*
interface customInterface<T1,T2> {
    property : T1;
    moreProperty : T2;
}

const obj : customInterface<string,number> = {
    property: "10",
    moreProperty : 20
}
console.log(obj);
*/
