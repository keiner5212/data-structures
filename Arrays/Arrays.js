/**
 * This program demonstrates the declaration, assignment, and access of elements in an integer array.
 * It declares an array of integers with 5 elements, assigns values to each element,
 * and then prints the elements of the array to the console.
 */
function main() {
	// Declaration of an array of integers with 5 elements
	const miArray = [];

	// Assignment of values to the elements of the array
	miArray[0] = 10;
	miArray[1] = 20;
	miArray[2] = 30;
	miArray[3] = 40;
	miArray[4] = 50;

	// Same as: const miArray = [10, 20, 30, 40, 50];

	// Accessing the elements of the array and printing to the console
	for (let i = 0; i < 5; i++) {
		console.log(`Element ${i}: ${miArray[i]}`);
	}
}

// Call the main function
main();
