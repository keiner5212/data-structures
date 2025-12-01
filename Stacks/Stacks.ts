/**
 * Stack implementation using array with LIFO (Last In First Out) operations.
 */
class Stack<T> {
    private items: T[];

    constructor() {
        this.items = [];
    }

    /**
     * Add element to the top of the stack. O(1) operation.
     */
    push(item: T): void {
        this.items.push(item);
    }

    /**
     * Remove and return top element from the stack. O(1) operation.
     */
    pop(): T | null {
        if (this.isEmpty()) {
            return null;
        }
        return this.items.pop() as T;
    }

    /**
     * Check if stack is empty. O(1) operation.
     */
    isEmpty(): boolean {
        return this.items.length === 0;
    }
    
    /**
     * Return top element without removing it. O(1) operation.
     */
    peek(): T | null {
        if (this.isEmpty()) {
            return null;
        }
        return this.items[this.items.length - 1];
    }
    
    /**
     * Return number of elements in stack. O(1) operation.
     */
    size(): number {
        return this.items.length;
    }
}

/**
 * Demonstrates stack operations with LIFO behavior.
 * Pushes 5 integers and pops them to show reverse ordering.
 */
function main(): void {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Create stack instance
    const myStack = new Stack<number>();
    
    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    // Pop and print elements
    console.log("Elements in the Stack:");
    while (!myStack.isEmpty()) {
        console.log(`Popped Element: ${myStack.pop()}`);
    }
    
    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;
    
    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log("\nTime Complexity:");
    console.log("  - Push: O(1)");
    console.log("  - Pop: O(1)");
    console.log("  - Peek: O(1)");
    console.log("  - IsEmpty: O(1)");
}

main();
