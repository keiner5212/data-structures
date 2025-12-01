package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Queue represents a FIFO data structure
type Queue struct {
	items []interface{}
}

// Enqueue adds element to the rear of the queue. O(1) operation.
func (q *Queue) enqueue(item interface{}) {
	q.items = append(q.items, item)
}

// Dequeue removes and returns front element from the queue. O(n) operation.
func (q *Queue) dequeue() interface{} {
	if q.isEmpty() {
		return nil
	}
	item := q.items[0]
	q.items = q.items[1:]
	return item
}

// IsEmpty checks if queue is empty. O(1) operation.
func (q *Queue) isEmpty() bool {
	return len(q.items) == 0
}

// Peek returns front element without removing it. O(1) operation.
func (q *Queue) peek() interface{} {
	if q.isEmpty() {
		return nil
	}
	return q.items[0]
}

// Size returns number of elements in queue. O(1) operation.
func (q *Queue) size() int {
	return len(q.items)
}

// Demonstrates queue operations with FIFO behavior.
// Enqueues 5 integers and dequeues them to show ordering.
func main() {
	startTime := time.Now()

	// Create queue instance
	myQueue := Queue{}

	// Enqueue elements
	myQueue.enqueue(10)
	myQueue.enqueue(20)
	myQueue.enqueue(30)
	myQueue.enqueue(40)
	myQueue.enqueue(50)

	// Calculate memory usage
	memoryUsed := unsafe.Sizeof(myQueue) + uintptr(len(myQueue.items))*unsafe.Sizeof(myQueue.items[0])

	// Dequeue and print elements
	fmt.Println("Elements in the Queue:")
	for !myQueue.isEmpty() {
		fmt.Printf("Dequeued Element: %v\n", myQueue.dequeue())
	}

	elapsed := time.Since(startTime)

	// Performance statistics
	fmt.Println("\n--- Performance Statistics ---")
	fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
	fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
	fmt.Println("\nTime Complexity:")
	fmt.Println("  - Enqueue: O(1)")
	fmt.Println("  - Dequeue: O(n)")
	fmt.Println("  - Peek: O(1)")
	fmt.Println("  - IsEmpty: O(1)")
}
