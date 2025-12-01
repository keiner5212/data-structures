/**
 * Queue implementation using array with FIFO (First In First Out) operations.
 */
class Queue {
    constructor() {
        this.items = [];
    }

    /**
     * Add element to the rear of the queue. O(1) operation.
     */
    enqueue(item) {
        this.items.push(item);
    }

    /**
     * Remove and return front element from the queue. O(n) operation.
     */
    dequeue() {
        if (this.isEmpty()) {
            return null;
        }
        return this.items.shift();
    }

    /**
     * Check if queue is empty. O(1) operation.
     */
    isEmpty() {
        return this.items.length === 0;
    }
    
    /**
     * Return front element without removing it. O(1) operation.
     */
    peek() {
        if (this.isEmpty()) {
            return null;
        }
        return this.items[0];
    }
    
    /**
     * Return number of elements in queue. O(1) operation.
     */
    size() {
        return this.items.length;
    }
}

/**
 * Demonstrates queue operations with FIFO behavior.
 * Enqueues 5 integers and dequeues them to show ordering.
 */
function main() {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Create queue instance
    const myQueue = new Queue();
    
    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Dequeue and print elements
    console.log("Elements in the Queue:");
    while (!myQueue.isEmpty()) {
        console.log(`Dequeued Element: ${myQueue.dequeue()}`);
    }
    
    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;
    
    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log("\nTime Complexity:");
    console.log("  - Enqueue: O(1)");
    console.log("  - Dequeue: O(n)");
    console.log("  - Peek: O(1)");
    console.log("  - IsEmpty: O(1)");
}

main();
