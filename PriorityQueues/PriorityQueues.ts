/**
 * Demonstrates priority queue operations: insert and extract_min.
 * Inserts values and extracts them in ascending order.
 */
class PriorityQueue {
    private heap: number[];

    constructor() {
        this.heap = [];
    }

    insert(val: number): void {
        this.heap.push(val);
        this.heapifyUp(this.heap.length - 1);
    }

    extractMin(): number {
        if (this.heap.length === 0) {
            throw new Error("extract from empty priority queue");
        }
        const minVal: number = this.heap[0];
        const lastVal: number = this.heap.pop()!;
        if (this.heap.length > 0) {
            this.heap[0] = lastVal;
            this.heapifyDown(0);
        }
        return minVal;
    }

    peek(): number {
        if (this.heap.length === 0) {
            throw new Error("peek from empty priority queue");
        }
        return this.heap[0];
    }

    isEmpty(): boolean {
        return this.heap.length === 0;
    }

    private heapifyUp(index: number): void {
        while (index > 0) {
            const parent: number = Math.floor((index - 1) / 2);
            if (this.heap[index] < this.heap[parent]) {
                [this.heap[index], this.heap[parent]] = [this.heap[parent], this.heap[index]];
                index = parent;
            } else {
                break;
            }
        }
    }

    private heapifyDown(index: number): void {
        const size: number = this.heap.length;
        while (true) {
            let left: number = 2 * index + 1;
            let right: number = 2 * index + 2;
            let smallest: number = index;
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

function main(): void {
    const startTime: number = performance.now();
    const memoryBefore: number = process.memoryUsage().heapUsed;

    const pq: PriorityQueue = new PriorityQueue();
    const values: number[] = [3, 1, 4, 1, 5, 9, 2, 6];

    for (const val of values) {
        pq.insert(val);
    }

    const extracted: number[] = [];
    while (!pq.isEmpty()) {
        extracted.push(pq.extractMin());
    }

    for (const val of extracted) {
        console.log(val);
    }

    const endTime: number = performance.now();
    const memoryAfter: number = process.memoryUsage().heapUsed;
    const memoryUsed: number = memoryAfter - memoryBefore;

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
