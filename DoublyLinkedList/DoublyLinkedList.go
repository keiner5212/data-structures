// Doubly linked list implementation with basic operations.
// Each node contains data and pointers to both previous and next nodes.
package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Node represents a node in the doubly linked list
type Node[T comparable] struct {
	data T
	prev *Node[T]
	next *Node[T]
}

// NewNode creates a new node with the given data
func NewNode[T comparable](data T) *Node[T] {
	return &Node[T]{data: data, prev: nil, next: nil}
}

// DoublyLinkedList represents a doubly linked list
type DoublyLinkedList[T comparable] struct {
	head *Node[T]
	tail *Node[T]
	size int
}

// NewDoublyLinkedList creates a new empty doubly linked list
func NewDoublyLinkedList[T comparable]() *DoublyLinkedList[T] {
	return &DoublyLinkedList[T]{head: nil, tail: nil, size: 0}
}

// IsEmpty checks if the list is empty. O(1) operation.
func (dll *DoublyLinkedList[T]) IsEmpty() bool {
	return dll.head == nil
}

// GetSize returns the number of elements in the list. O(1) operation.
func (dll *DoublyLinkedList[T]) GetSize() int {
	return dll.size
}

// InsertAtBeginning inserts an element at the beginning of the list. O(1) operation.
func (dll *DoublyLinkedList[T]) InsertAtBeginning(data T) {
	newNode := NewNode(data)
	if dll.IsEmpty() {
		dll.head = newNode
		dll.tail = newNode
	} else {
		newNode.next = dll.head
		dll.head.prev = newNode
		dll.head = newNode
	}
	dll.size++
}

// InsertAtEnd inserts an element at the end of the list. O(1) operation.
func (dll *DoublyLinkedList[T]) InsertAtEnd(data T) {
	newNode := NewNode(data)
	if dll.IsEmpty() {
		dll.head = newNode
		dll.tail = newNode
	} else {
		newNode.prev = dll.tail
		dll.tail.next = newNode
		dll.tail = newNode
	}
	dll.size++
}

// InsertAtPosition inserts an element at the specified position. O(n) operation.
func (dll *DoublyLinkedList[T]) InsertAtPosition(data T, position int) {
	if position < 0 || position > dll.size {
		panic("Invalid position")
	}

	if position == 0 {
		dll.InsertAtBeginning(data)
		return
	}

	if position == dll.size {
		dll.InsertAtEnd(data)
		return
	}

	newNode := NewNode(data)
	current := dll.head
	for i := 0; i < position-1; i++ {
		current = current.next
	}

	newNode.next = current.next
	newNode.prev = current
	current.next.prev = newNode
	current.next = newNode
	dll.size++
}

// DeleteFromBeginning deletes the element from the beginning of the list. O(1) operation.
func (dll *DoublyLinkedList[T]) DeleteFromBeginning() T {
	if dll.IsEmpty() {
		panic("List is empty")
	}

	deletedData := dll.head.data
	if dll.head == dll.tail {
		dll.head = nil
		dll.tail = nil
	} else {
		dll.head = dll.head.next
		dll.head.prev = nil
	}
	dll.size--
	return deletedData
}

// DeleteFromEnd deletes the element from the end of the list. O(1) operation.
func (dll *DoublyLinkedList[T]) DeleteFromEnd() T {
	if dll.IsEmpty() {
		panic("List is empty")
	}

	deletedData := dll.tail.data
	if dll.head == dll.tail {
		dll.head = nil
		dll.tail = nil
	} else {
		dll.tail = dll.tail.prev
		dll.tail.next = nil
	}
	dll.size--
	return deletedData
}

// DeleteByValue deletes the first occurrence of the value. O(n) operation.
func (dll *DoublyLinkedList[T]) DeleteByValue(value T) bool {
	if dll.IsEmpty() {
		return false
	}

	current := dll.head
	for current != nil {
		if current.data == value {
			if current == dll.head {
				dll.DeleteFromBeginning()
			} else if current == dll.tail {
				dll.DeleteFromEnd()
			} else {
				current.prev.next = current.next
				current.next.prev = current.prev
				dll.size--
			}
			return true
		}
		current = current.next
	}
	return false
}

// Search searches for a value in the list. O(n) operation.
func (dll *DoublyLinkedList[T]) Search(value T) int {
	current := dll.head
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

// DisplayForward prints all elements from head to tail.
func (dll *DoublyLinkedList[T]) DisplayForward() {
	if dll.IsEmpty() {
		fmt.Println("List is empty")
		return
	}

	current := dll.head
	for current != nil {
		fmt.Print(current.data)
		if current.next != nil {
			fmt.Print(" -> ")
		}
		current = current.next
	}
	fmt.Println()
}

// DisplayBackward prints all elements from tail to head.
func (dll *DoublyLinkedList[T]) DisplayBackward() {
	if dll.IsEmpty() {
		fmt.Println("List is empty")
		return
	}

	current := dll.tail
	for current != nil {
		fmt.Print(current.data)
		if current.prev != nil {
			fmt.Print(" <- ")
		}
		current = current.prev
	}
	fmt.Println()
}

// main demonstrates doubly linked list operations.
// Performs insertions, deletions, and searches on the list.
func main() {
	startTime := time.Now()

	// Create doubly linked list instance
	dll := NewDoublyLinkedList[int]()

	// Insert elements
	dll.InsertAtEnd(10)
	dll.InsertAtEnd(20)
	dll.InsertAtBeginning(5)
	dll.InsertAtPosition(15, 2)

	fmt.Println("List after insertions (forward):")
	dll.DisplayForward()

	fmt.Println("\nList after insertions (backward):")
	dll.DisplayBackward()

	// Search operations
	searchValues := []int{15, 25}
	fmt.Println("\nSearch results:")
	for _, value := range searchValues {
		position := dll.Search(value)
		if position != -1 {
			fmt.Printf("Value %d found at position %d\n", value, position)
		} else {
			fmt.Printf("Value %d not found\n", value)
		}
	}

	// Delete operations
	dll.DeleteByValue(20)
	fmt.Println("\nList after deleting 20 (forward):")
	dll.DisplayForward()

	dll.DeleteFromBeginning()
	fmt.Println("\nList after deleting from beginning (forward):")
	dll.DisplayForward()

	dll.DeleteFromEnd()
	fmt.Println("\nList after deleting from end (forward):")
	dll.DisplayForward()

	endTime := time.Now()
	executionTime := endTime.Sub(startTime)

	// Calculate memory usage (approximate)
	var dummyNode Node[int]
	nodeSize := unsafe.Sizeof(dummyNode)
	memoryUsed := uintptr(dll.size) * nodeSize

	// Performance statistics
	fmt.Println("\n--- Performance Statistics ---")
	fmt.Printf("Execution time: %.4f ms\n", float64(executionTime.Nanoseconds())/1e6)
	fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
	fmt.Printf("Final list size: %d\n", dll.GetSize())
	fmt.Println("\nTime Complexity:")
	fmt.Println("  - Insert at beginning: O(1)")
	fmt.Println("  - Insert at end: O(1)")
	fmt.Println("  - Insert at position: O(n)")
	fmt.Println("  - Delete from beginning: O(1)")
	fmt.Println("  - Delete from end: O(1)")
	fmt.Println("  - Delete by value: O(n)")
	fmt.Println("  - Search: O(n)")
	fmt.Println("  - Get size: O(1)")
}