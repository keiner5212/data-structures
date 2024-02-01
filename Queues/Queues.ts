// Queue class
class Queue {
    private items: any[];

    constructor() {
        this.items = [];
    }

    // Enqueue method to add elements to the queue
    enqueue(item: any): void {
        this.items.push(item);
    }

    // Dequeue method to remove and return the front element from the queue
    dequeue(): any {
        if (this.isEmpty()) {
            return -1; // Indicates empty queue
        }
        return this.items.shift();
    }

    // IsEmpty method to check if the queue is empty
    isEmpty(): boolean {
        return this.items.length === 0;
    }
}

// Create an instance of the queue
const myQueue = new Queue();

// Enqueue elements to the queue
myQueue.enqueue(10);
myQueue.enqueue(20);
myQueue.enqueue(30);
myQueue.enqueue(40);
myQueue.enqueue(50);

// Access and print the elements of the queue
console.log("Elements in the Queue:");
while (!myQueue.isEmpty()) {
    console.log(`Dequeued Element: ${myQueue.dequeue()}`);
}
