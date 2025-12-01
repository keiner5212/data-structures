/**
 * Singly linked list implementation with basic operations.
 * Each node contains data and a reference to the next node.
 */
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor() {
        this.head = null;
        this.size = 0;
    }

    /**
     * Check if list is empty. O(1) operation.
     */
    isEmpty() {
        return this.head === null;
    }

    /**
     * Return number of elements in list. O(1) operation.
     */
    getSize() {
        return this.size;
    }

    /**
     * Insert element at the beginning of the list. O(1) operation.
     */
    insertAtBeginning(data) {
        const newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
        this.size++;
    }

    /**
     * Insert element at the end of the list. O(n) operation.
     */
    insertAtEnd(data) {
        const newNode = new Node(data);
        if (this.isEmpty()) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = newNode;
        }
        this.size++;
    }

    /**
     * Insert element at specified position. O(n) operation.
     */
    insertAtPosition(data, position) {
        if (position < 0 || position > this.size) {
            throw new Error("Invalid position");
        }

        if (position === 0) {
            this.insertAtBeginning(data);
            return;
        }

        const newNode = new Node(data);
        let current = this.head;
        for (let i = 0; i < position - 1; i++) {
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;
        this.size++;
    }

    /**
     * Delete element from the beginning of the list. O(1) operation.
     */
    deleteFromBeginning() {
        if (this.isEmpty()) {
            return null;
        }

        const deletedData = this.head.data;
        this.head = this.head.next;
        this.size--;
        return deletedData;
    }

    /**
     * Delete element from the end of the list. O(n) operation.
     */
    deleteFromEnd() {
        if (this.isEmpty()) {
            return null;
        }

        if (this.head.next === null) {
            const deletedData = this.head.data;
            this.head = null;
            this.size--;
            return deletedData;
        }

        let current = this.head;
        while (current.next.next) {
            current = current.next;
        }

        const deletedData = current.next.data;
        current.next = null;
        this.size--;
        return deletedData;
    }

    /**
     * Delete first occurrence of value. O(n) operation.
     */
    deleteByValue(value) {
        if (this.isEmpty()) {
            return false;
        }

        if (this.head.data === value) {
            this.head = this.head.next;
            this.size--;
            return true;
        }

        let current = this.head;
        while (current.next && current.next.data !== value) {
            current = current.next;
        }

        if (current.next) {
            current.next = current.next.next;
            this.size--;
            return true;
        }

        return false;
    }

    /**
     * Search for value in the list. O(n) operation.
     */
    search(value) {
        let current = this.head;
        let position = 0;
        while (current) {
            if (current.data === value) {
                return position;
            }
            current = current.next;
            position++;
        }
        return -1;
    }

    /**
     * Display all elements in the list.
     */
    display() {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let current = this.head;
        const elements = [];
        while (current) {
            elements.push(current.data.toString());
            current = current.next;
        }
        console.log(elements.join(" -> "));
    }
}

/**
 * Demonstrates singly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
function main() {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Create linked list instance
    const sll = new SinglyLinkedList();
    
    // Insert elements
    sll.insertAtEnd(10);
    sll.insertAtEnd(20);
    sll.insertAtBeginning(5);
    sll.insertAtPosition(15, 2);
    
    console.log("List after insertions:");
    sll.display();
    
    // Search operations
    const searchValues = [15, 25];
    console.log("\nSearch results:");
    for (const value of searchValues) {
        const position = sll.search(value);
        if (position !== -1) {
            console.log(`Value ${value} found at position ${position}`);
        } else {
            console.log(`Value ${value} not found`);
        }
    }
    
    // Delete operations
    sll.deleteByValue(20);
    console.log("\nList after deleting 20:");
    sll.display();
    
    sll.deleteFromBeginning();
    console.log("\nList after deleting from beginning:");
    sll.display();
    
    sll.deleteFromEnd();
    console.log("\nList after deleting from end:");
    sll.display();
    
    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;
    
    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log(`Final list size: ${sll.getSize()}`);
    console.log("\nTime Complexity:");
    console.log("  - Insert at beginning: O(1)");
    console.log("  - Insert at end: O(n)");
    console.log("  - Insert at position: O(n)");
    console.log("  - Delete from beginning: O(1)");
    console.log("  - Delete from end: O(n)");
    console.log("  - Delete by value: O(n)");
    console.log("  - Search: O(n)");
    console.log("  - Get size: O(1)");
}

main();