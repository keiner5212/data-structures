package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Stack represents a LIFO data structure
type Stack struct {
	items []interface{}
}

// Push adds an element to the top of the stack. O(1) operation.
func (s *Stack) Push(item interface{}) {
	s.items = append(s.items, item)
}

// Pop removes and returns the top element from the stack. O(1) operation.
func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		return nil
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item
}

// IsEmpty checks if the stack is empty. O(1) operation.
func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

// Peek returns the top element without removing it. O(1) operation.
func (s *Stack) Peek() interface{} {
	if s.IsEmpty() {
		return nil
	}
	return s.items[len(s.items)-1]
}

// Size returns the number of elements in the stack. O(1) operation.
func (s *Stack) Size() int {
	return len(s.items)
}

// Demonstrates stack operations with LIFO behavior.
// Pushes 5 integers and pops them to show reverse ordering.
func main() {
	startTime := time.Now()

	// Create stack instance
	myStack := Stack{}

	// Push elements
	myStack.Push(10)
	myStack.Push(20)
	myStack.Push(30)
	myStack.Push(40)
	myStack.Push(50)

	// Calculate memory usage
	memoryUsed := unsafe.Sizeof(myStack) + uintptr(len(myStack.items))*unsafe.Sizeof(myStack.items[0])

	// Pop and print elements
	fmt.Println("Elements in the Stack:")
	for !myStack.IsEmpty() {
		fmt.Printf("Popped Element: %v\n", myStack.Pop())
	}

	elapsed := time.Since(startTime)

	// Performance statistics
	fmt.Println("\n--- Performance Statistics ---")
	fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
	fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
	fmt.Println("\nTime Complexity:")
	fmt.Println("  - Push: O(1)")
	fmt.Println("  - Pop: O(1)")
	fmt.Println("  - Peek: O(1)")
	fmt.Println("  - IsEmpty: O(1)")
}
