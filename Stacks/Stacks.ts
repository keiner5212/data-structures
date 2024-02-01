// Stack class
class Stack {
    private items: any[];

    constructor() {
        this.items = [];
    }

    // Push method to add elements to the stack
    push(item: any): void {
        this.items.push(item);
    }

    // Pop method to remove and return the top element from the stack
    pop(): any {
        if (this.isEmpty()) {
            return -1; // Indicates empty stack
        }
        return this.items.pop();
    }

    // IsEmpty method to check if the stack is empty
    isEmpty(): boolean {
        return this.items.length === 0;
    }
}

// Create an instance of the stack
const myStack = new Stack();

// Add elements to the stack
myStack.push(10);
myStack.push(20);
myStack.push(30);
myStack.push(40);
myStack.push(50);

// Access and print the elements of the stack
console.log("Elements in the Stack:");
while (!myStack.isEmpty()) {
    console.log(`Popped Element: ${myStack.pop()}`);
}
