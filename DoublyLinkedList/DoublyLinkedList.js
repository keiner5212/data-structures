/**
 * Doubly linked list implementation with basic operations.
 * Each node contains data and references to both previous and next nodes.
 */
class Node {
    constructor(data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
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
        if (this.isEmpty()) {
            this.head = this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.size++;
    }

    /**
     * Insert element at the end of the list. O(1) operation.
     */
    insertAtEnd(data) {
        const newNode = new Node(data);
        if (this.isEmpty()) {
            this.head = this.tail = newNode;
        } else {
            newNode.prev = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
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

        if (position === this.size) {
            this.insertAtEnd(data);
            return;
        }

        const newNode = new Node(data);
        let current = this.head;
        for (let i = 0; i < position - 1; i++) {
            current = current.next;
        }

        newNode.next = current.next;
        newNode.prev = current;
        current.next.prev = newNode;
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
        if (this.head === this.tail) {
            this.head = this.tail = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
        }
        this.size--;
        return deletedData;
    }

    /**
     * Delete element from the end of the list. O(1) operation.
     */
    deleteFromEnd() {
        if (this.isEmpty()) {
            return null;
        }

        const deletedData = this.tail.data;
        if (this.head === this.tail) {
            this.head = this.tail = null;
        } else {
            this.tail = this.tail.prev;
            this.tail.next = null;
        }
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

        let current = this.head;
        while (current) {
            if (current.data === value) {
                if (current === this.head) {
                    this.deleteFromBeginning();
                } else if (current === this.tail) {
                    this.deleteFromEnd();
                } else {
                    current.prev.next = current.next;
                    current.next.prev = current.prev;
                    this.size--;
                }
                return true;
            }
            current = current.next;
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
     * Display all elements from head to tail.
     */
    displayForward() {
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

    /**
     * Display all elements from tail to head.
     */
    displayBackward() {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let current = this.tail;
        const elements = [];
        while (current) {
            elements.push(current.data.toString());
            current = current.prev;
        }
        console.log(elements.join(" <- "));
    }
}

/**
 * Demonstrates doubly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
function main() {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;

    // Create doubly linked list instance
    const dll = new DoublyLinkedList();

    // Insert elements
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(15, 2);

    console.log("List after insertions (forward):");
    dll.displayForward();

    console.log("\nList after insertions (backward):");
    dll.displayBackward();

    // Search operations
    const searchValues = [15, 25];
    console.log("\nSearch results:");
    for (const value of searchValues) {
        const position = dll.search(value);
        if (position !== -1) {
            console.log(`Value ${value} found at position ${position}`);
        } else {
            console.log(`Value ${value} not found`);
        }
    }

    // Delete operations
    dll.deleteByValue(20);
    console.log("\nList after deleting 20 (forward):");
    dll.displayForward();

    dll.deleteFromBeginning();
    console.log("\nList after deleting from beginning (forward):");
    dll.displayForward();

    dll.deleteFromEnd();
    console.log("\nList after deleting from end (forward):");
    dll.displayForward();

    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;

    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log(`Final list size: ${dll.getSize()}`);
    console.log("\nTime Complexity:");
    console.log("  - Insert at beginning: O(1)");
    console.log("  - Insert at end: O(1)");
    console.log("  - Insert at position: O(n)");
    console.log("  - Delete from beginning: O(1)");
    console.log("  - Delete from end: O(1)");
    console.log("  - Delete by value: O(n)");
    console.log("  - Search: O(n)");
    console.log("  - Get size: O(1)");
}

main();