package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Demonstrates matrix declaration and element access.
// Creates a 2x3 matrix and prints all elements in row-column format.
func main() {
    startTime := time.Now()
    
    // Initialize 2x3 matrix
    matrix := [][]int{
        {1, 2, 3},
        {4, 5, 6},
    }
    
    memoryUsed := unsafe.Sizeof(matrix) + uintptr(len(matrix))*(unsafe.Sizeof(matrix[0])+uintptr(len(matrix[0]))*unsafe.Sizeof(matrix[0][0]))

    // Print matrix elements
    fmt.Println("Result Matrix:")
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[i]); j++ {
            fmt.Printf("%d ", matrix[i][j])
        }
        fmt.Println()
    }
    
    elapsed := time.Since(startTime)
    
    // Performance statistics
    fmt.Println("\n--- Performance Statistics ---")
    fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
    fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
    fmt.Println("\nTime Complexity:")
    fmt.Println("  - Access: O(1)")
    fmt.Println("  - Search: O(m*n)")
    fmt.Println("  - Insertion (row/col): O(m*n)")
    fmt.Println("  - Traversal: O(m*n)")
}
