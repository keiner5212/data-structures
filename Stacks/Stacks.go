package main

import "fmt"

// Stack structure
type Stack struct {
	items []int
}

// Push adds an element to the stack
func (s *Stack) Push(item int) {
	s.items = append(s.items, item)
}

// Pop removes and returns the top element from the stack
func (s *Stack) Pop() int {
	if len(s.items) == 0 {
		return -1 // Indicates empty stack
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item
}

// IsEmpty checks if the stack is empty
func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}


func main() {
	// Create an instance of the stack
	myStack := Stack{}

	// Add elements to the stack
	myStack.Push(10)
	myStack.Push(20)
	myStack.Push(30)
	myStack.Push(40)
	myStack.Push(50)

	// Access and print the elements of the stack
	for !myStack.IsEmpty() {
		fmt.Printf("Popped Element: %d\n", myStack.Pop())
	}
}
