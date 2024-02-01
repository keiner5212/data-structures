/**
 * This program demonstrates basic operations with matrices.
 */
function main(): void {
    // Declaration of matrices
    const matrix1: number[][] = [
        [1, 2, 3],
        [4, 5, 6],
    ];

    // Printing the matrix
    console.log("Result Matrix:");
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 3; j++) {
            process.stdout.write(matrix1[i][j] + " ");
        }
        console.log();
    }
}

// Call the main function
main();
