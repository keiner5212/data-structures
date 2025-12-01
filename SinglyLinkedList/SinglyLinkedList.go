// Singly linked list implementation with basic operations.
// Each node contains data and a pointer to the next node.
package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Node represents a node in the singly linked list
type Node[T comparable] struct {
	data T
	next *Node[T]
}

// NewNode creates a new node with the given data
func NewNode[T comparable](data T) *Node[T] {
	return &Node[T]{data: data, next: nil}
}

// SinglyLinkedList represents a singly linked list
type SinglyLinkedList[T comparable] struct {
	head *Node[T]
	size int
}

// NewSinglyLinkedList creates a new empty singly linked list
func NewSinglyLinkedList[T comparable]() *SinglyLinkedList[T] {
	return &SinglyLinkedList[T]{head: nil, size: 0}
}

// IsEmpty checks if the list is empty. O(1) operation.
func (sll *SinglyLinkedList[T]) IsEmpty() bool {
	return sll.head == nil
}

// GetSize returns the number of elements in the list. O(1) operation.
func (sll *SinglyLinkedList[T]) GetSize() int {
	return sll.size
}

// InsertAtBeginning inserts an element at the beginning of the list. O(1) operation.
func (sll *SinglyLinkedList[T]) InsertAtBeginning(data T) {
	newNode := NewNode(data)
	newNode.next = sll.head
	sll.head = newNode
	sll.size++
}

// InsertAtEnd inserts an element at the end of the list. O(n) operation.
func (sll *SinglyLinkedList[T]) InsertAtEnd(data T) {
	newNode := NewNode(data)
	if sll.IsEmpty() {
		sll.head = newNode
	} else {
		current := sll.head
		for current.next != nil {
			current = current.next
		}
		current.next = newNode
	}
	sll.size++
}

// InsertAtPosition inserts an element at the specified position. O(n) operation.
func (sll *SinglyLinkedList[T]) InsertAtPosition(data T, position int) {
	if position < 0 || position > sll.size {
		panic("Invalid position")
	}

	if position == 0 {
		sll.InsertAtBeginning(data)
		return
	}

	newNode := NewNode(data)
	current := sll.head
	for i := 0; i < position-1; i++ {
		current = current.next
	}

	newNode.next = current.next
	current.next = newNode
	sll.size++
}

// DeleteFromBeginning deletes the element from the beginning of the list. O(1) operation.
func (sll *SinglyLinkedList[T]) DeleteFromBeginning() T {
	if sll.IsEmpty() {
		panic("List is empty")
	}

	deletedData := sll.head.data
	sll.head = sll.head.next
	sll.size--
	return deletedData
}

// DeleteFromEnd deletes the element from the end of the list. O(n) operation.
func (sll *SinglyLinkedList[T]) DeleteFromEnd() T {
	if sll.IsEmpty() {
		panic("List is empty")
	}

	if sll.head.next == nil {
		deletedData := sll.head.data
		sll.head = nil
		sll.size--
		return deletedData
	}

	current := sll.head
	for current.next.next != nil {
		current = current.next
	}

	deletedData := current.next.data
	current.next = nil
	sll.size--
	return deletedData
}

// DeleteByValue deletes the first occurrence of the value. O(n) operation.
func (sll *SinglyLinkedList[T]) DeleteByValue(value T) bool {
	if sll.IsEmpty() {
		return false
	}

	if sll.head.data == value {
		sll.head = sll.head.next
		sll.size--
		return true
	}

	current := sll.head
	for current.next != nil && current.next.data != value {
		current = current.next
	}

	if current.next != nil {
		current.next = current.next.next
		sll.size--
		return true
	}

	return false
}

// Search searches for a value in the list. O(n) operation.
func (sll *SinglyLinkedList[T]) Search(value T) int {
	current := sll.head
	position := 0
	for current != nil {
		if current.data == value {
			return position
		}
		current = current.next
		position++
	}
	return -1
}

// Display prints all elements in the list.
func (sll *SinglyLinkedList[T]) Display() {
	if sll.IsEmpty() {
		fmt.Println("List is empty")
		return
	}

	current := sll.head
	for current != nil {
		fmt.Print(current.data)
		if current.next != nil {
			fmt.Print(" -> ")
		}
		current = current.next
	}
	fmt.Println()
}

// main demonstrates singly linked list operations.
// Performs insertions, deletions, and searches on the list.
func main() {
	startTime := time.Now()

	// Create linked list instance
	sll := NewSinglyLinkedList[int]()

	// Insert elements
	sll.InsertAtEnd(10)
	sll.InsertAtEnd(20)
	sll.InsertAtBeginning(5)
	sll.InsertAtPosition(15, 2)

	fmt.Println("List after insertions:")
	sll.Display()

	// Search operations
	searchValues := []int{15, 25}
	fmt.Println("\nSearch results:")
	for _, value := range searchValues {
		position := sll.Search(value)
		if position != -1 {
			fmt.Printf("Value %d found at position %d\n", value, position)
		} else {
			fmt.Printf("Value %d not found\n", value)
		}
	}

	// Delete operations
	sll.DeleteByValue(20)
	fmt.Println("\nList after deleting 20:")
	sll.Display()

	sll.DeleteFromBeginning()
	fmt.Println("\nList after deleting from beginning:")
	sll.Display()

	sll.DeleteFromEnd()
	fmt.Println("\nList after deleting from end:")
	sll.Display()

	endTime := time.Now()
	executionTime := endTime.Sub(startTime)

	// Calculate memory usage (approximate)
	var dummyNode Node[int]
	nodeSize := unsafe.Sizeof(dummyNode)
	memoryUsed := uintptr(sll.size) * nodeSize

	// Performance statistics
	fmt.Println("\n--- Performance Statistics ---")
	fmt.Printf("Execution time: %.4f ms\n", float64(executionTime.Nanoseconds())/1e6)
	fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
	fmt.Printf("Final list size: %d\n", sll.GetSize())
	fmt.Println("\nTime Complexity:")
	fmt.Println("  - Insert at beginning: O(1)")
	fmt.Println("  - Insert at end: O(n)")
	fmt.Println("  - Insert at position: O(n)")
	fmt.Println("  - Delete from beginning: O(1)")
	fmt.Println("  - Delete from end: O(n)")
	fmt.Println("  - Delete by value: O(n)")
	fmt.Println("  - Search: O(n)")
	fmt.Println("  - Get size: O(1)")
}