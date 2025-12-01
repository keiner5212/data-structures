package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Demonstrates array declaration, initialization, and element access.
// Creates an array with 5 integers and prints each element with its index.
func main() {
    startTime := time.Now()
    
    // Initialize array with 5 elements
    myArray := [5]int{10, 20, 30, 40, 50}
    
    memoryUsed := unsafe.Sizeof(myArray)

    // Iterate through array and print each element
    for i := 0; i < len(myArray); i++ {
        fmt.Printf("Element %d: %d\n", i, myArray[i])
    }
    
    elapsed := time.Since(startTime)
    
    // Performance statistics
    fmt.Println("\n--- Performance Statistics ---")
    fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
    fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
    fmt.Println("\nTime Complexity:")
    fmt.Println("  - Access: O(1)")
    fmt.Println("  - Search: O(n)")
    fmt.Println("  - Insertion: O(n)")
    fmt.Println("  - Deletion: O(n)")
}
