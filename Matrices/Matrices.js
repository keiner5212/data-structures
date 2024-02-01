/**
 * This program demonstrates basic operations with matrices.
 */
function main() {
	// Declaration of matrices
	const matrix1 = [
		[1, 2, 3],
		[4, 5, 6],
	];

	// Printing the matrix
	console.log("Result Matrix:");
	for (let i = 0; i < 2; i++) {
		for (let j = 0; j < 3; j++) {
			process.stdout.write(matrix1[i][j] + " "); //this is how you print without new line in js
		}
		console.log();
	}
}

main();
