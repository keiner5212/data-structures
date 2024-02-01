package main

import "fmt"

// This program demonstrates the declaration, assignment, and access of elements in an integer array.
// It declares an array of integers with 5 elements, assigns values to each element, and then prints
// the elements of the array to the console.
//
func main() {
    // Declaration and initialization of an array of integers with 5 elements
    miArray := [5]int{10, 20, 30, 40, 50}

    // Accessing the elements of the array and printing to the console
    for i := 0; i < 5; i++ {
        fmt.Printf("Element %d: %d\n", i, miArray[i])
    }

    // Alternatively, you can use a range-based loop:
    // for i, value := range miArray {
    //     fmt.Printf("Element %d: %d\n", i, value)
    // }
    return
}
