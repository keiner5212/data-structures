/**
 * Demonstrates matrix declaration and element access.
 * Creates a 2x3 matrix and prints all elements in row-column format.
 */
function main(): void {
    const startTime = performance.now();
    const memoryBefore = process.memoryUsage().heapUsed;
    
    // Initialize 2x3 matrix
    const matrix: number[][] = [
        [1, 2, 3],
        [4, 5, 6],
    ];

    // Print matrix elements
    console.log("Result Matrix:");
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            process.stdout.write(matrix[i][j] + " ");
        }
        console.log();
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
    console.log("  - Search: O(m*n)");
    console.log("  - Insertion (row/col): O(m*n)");
    console.log("  - Traversal: O(m*n)");
}

main();
