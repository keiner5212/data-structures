package main

import "fmt"

/**
 * @brief This program demonstrates basic operations with matrices.
 * @return 0 indicating successful execution.
 */
func main() {
	// Declaration of matrices
	matrix1 := [][]int{
		{1, 2, 3},
		{4, 5, 6},
	}

	// Printing the matrix
	fmt.Println("Result Matrix:")
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			fmt.Printf("%d ", matrix1[i][j])
		}
		fmt.Println()
	}

	return
}
