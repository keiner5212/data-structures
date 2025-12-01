/**
 * SkipList implementation with probabilistic level assignment.
 * Provides O(log n) average time for search, insert, and delete operations.
 */
class SkipListNode {
    key: number;
    forward: (SkipListNode | null)[];

    constructor(key: number, level: number) {
        this.key = key;
        this.forward = new Array(level + 1).fill(null);
    }
}

class SkipList {
    private maxLevel: number;
    private p: number;
    private header: SkipListNode;
    private level: number;

    constructor(maxLevel: number = 16, p: number = 0.5) {
        this.maxLevel = maxLevel;
        this.p = p;
        this.header = new SkipListNode(-Infinity, maxLevel);
        this.level = 0;
    }

    /**
     * Generate random level for new node.
     */
    private randomLevel(): number {
        let level = 0;
        while (Math.random() < this.p && level < this.maxLevel) {
            level++;
        }
        return level;
    }

    /**
     * Search for key in SkipList. O(log n) average time.
     */
    search(key: number): number | null {
        let current = this.header;
        for (let i = this.level; i >= 0; i--) {
            while (current.forward[i] && current.forward[i]!.key < key) {
                current = current.forward[i]!;
            }
        }

        current = current.forward[0]!;
        if (current && current.key === key) {
            return current.key;
        }
        return null;
    }

    /**
     * Insert key into SkipList. O(log n) average time.
     */
    insert(key: number): void {
        const update: (SkipListNode | null)[] = new Array(this.maxLevel + 1).fill(null);
        let current = this.header;

        for (let i = this.level; i >= 0; i--) {
            while (current.forward[i] && current.forward[i]!.key < key) {
                current = current.forward[i]!;
            }
            update[i] = current;
        }

        current = current.forward[0]!;

        if (!current || current.key !== key) {
            const newLevel = this.randomLevel();

            if (newLevel > this.level) {
                for (let i = this.level + 1; i <= newLevel; i++) {
                    update[i] = this.header;
                }
                this.level = newLevel;
            }

            const newNode = new SkipListNode(key, newLevel);

            for (let i = 0; i <= newLevel; i++) {
                newNode.forward[i] = update[i]!.forward[i];
                update[i]!.forward[i] = newNode;
            }
        }
    }

    /**
     * Delete key from SkipList. O(log n) average time.
     */
    delete(key: number): void {
        const update: (SkipListNode | null)[] = new Array(this.maxLevel + 1).fill(null);
        let current = this.header;

        for (let i = this.level; i >= 0; i--) {
            while (current.forward[i] && current.forward[i]!.key < key) {
                current = current.forward[i]!;
            }
            update[i] = current;
        }

        current = current.forward[0]!;

        if (current && current.key === key) {
            for (let i = 0; i <= this.level; i++) {
                if (update[i]!.forward[i] !== current) {
                    break;
                }
                update[i]!.forward[i] = current.forward[i];
            }

            while (this.level > 0 && !this.header.forward[this.level]) {
                this.level--;
            }
        }
    }

    /**
     * Display SkipList structure.
     */
    display(): void {
        console.log("SkipList structure:");
        for (let level = this.level; level >= 0; level--) {
            let current = this.header.forward[level];
            let levelStr = `Level ${level}: `;
            while (current) {
                levelStr += `${current.key} -> `;
                current = current.forward[level];
            }
            levelStr += "None";
            console.log(levelStr);
        }
    }
}

/**
 * Demonstrates SkipList operations with probabilistic balancing.
 * Inserts 10 elements, searches for values, and displays structure.
 */
function main(): void {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Create SkipList instance
    const skipList = new SkipList();
    
    // Insert elements
    const elements = [3, 6, 7, 9, 12, 19, 17, 26, 21, 25];
    for (const elem of elements) {
        skipList.insert(elem);
    }

    // Display structure
    skipList.display();
    
    // Search operations
    const searchKeys = [19, 15, 21];
    console.log("\nSearch results:");
    for (const key of searchKeys) {
        const result = skipList.search(key);
        console.log(`Search for ${key}: ${result ? 'Found' : 'Not found'}`);
    }
    
    // Delete operation
    skipList.delete(17);
    console.log("\nAfter deleting 17:");
    skipList.display();
    
    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;
    
    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log("\nTime Complexity (Average):");
    console.log("  - Search: O(log n)");
    console.log("  - Insert: O(log n)");
    console.log("  - Delete: O(log n)");
    console.log("  - Space: O(n)");
}

main();