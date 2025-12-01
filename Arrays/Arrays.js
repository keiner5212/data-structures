/**
 * Demonstrates array declaration, initialization, and element access.
 * Creates an array with 5 integers and prints each element with its index.
 */
function main() {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Initialize array with 5 elements
    const myArray = [10, 20, 30, 40, 50];

    // Iterate through array and print each element
    for (let i = 0; i < myArray.length; i++) {
        console.log(`Element ${i}: ${myArray[i]}`);
    }
    
    const endTime = performance.now();
    const memoryAfter = process.memoryUsage().heapUsed;
    const memoryUsed = memoryAfter - memoryBefore;
    
    // Performance statistics
    console.log("\n--- Performance Statistics ---");
    console.log(`Execution time: ${(endTime - startTime).toFixed(4)} ms`);
    console.log(`Memory usage: ${memoryUsed > 0 ? memoryUsed : 'negligible'} bytes`);
    console.log("\nTime Complexity:");
    console.log("  - Access: O(1)");
    console.log("  - Search: O(n)");
    console.log("  - Insertion: O(n)");
    console.log("  - Deletion: O(n)");
}

main();
