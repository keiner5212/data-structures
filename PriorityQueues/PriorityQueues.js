/**
 * Demonstrates priority queue operations: insert and extract_min.
 * Inserts values and extracts them in ascending order.
 */
class PriorityQueue {
    constructor() {
        this.heap = [];
    }

    insert(val) {
        this.heap.push(val);
        this.heapifyUp(this.heap.length - 1);
    }

    extractMin() {
        if (this.heap.length === 0) {
            throw new Error("extract from empty priority queue");
        }
        const minVal = this.heap[0];
        const lastVal = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = lastVal;
            this.heapifyDown(0);
        }
        return minVal;
    }

    peek() {
        if (this.heap.length === 0) {
            throw new Error("peek from empty priority queue");
        }
        return this.heap[0];
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    heapifyUp(index) {
        while (index > 0) {
            const parent = Math.floor((index - 1) / 2);
            if (this.heap[index] < this.heap[parent]) {
                [this.heap[index], this.heap[parent]] = [this.heap[parent], this.heap[index]];
                index = parent;
            } else {
                break;
            }
        }
    }

    heapifyDown(index) {
        const size = this.heap.length;
        while (true) {
            let left = 2 * index + 1;
            let right = 2 * index + 2;
            let smallest = index;
            if (left < size && this.heap[left] < this.heap[smallest]) {
                smallest = left;
            }
            if (right < size && this.heap[right] < this.heap[smallest]) {
                smallest = right;
            }
            if (smallest !== index) {
                [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
                index = smallest;
            } else {
                break;
            }
        }
    }
}

function main() {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;

    const pq = new PriorityQueue();
    const values = [3, 1, 4, 1, 5, 9, 2, 6];

    for (const val of values) {
        pq.insert(val);
    }

    const extracted = [];
    while (!pq.isEmpty()) {
        extracted.push(pq.extractMin());
    }

    for (const val of extracted) {
        console.log(val);
    }

    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;

    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log("\nTime Complexity:");
    console.log("  - Insert: O(log n)");
    console.log("  - Extract_min: O(log n)");
    console.log("  - Peek: O(1)");
}

main();
