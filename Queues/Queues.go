package main

import "fmt"

// Queue struct
type Queue struct {
	items []interface{}
}

// Enqueue method to add elements to the queue
func (q *Queue) enqueue(item interface{}) {
	q.items = append(q.items, item)
}

// Dequeue method to remove and return the front element from the queue
func (q *Queue) dequeue() interface{} {
	if q.isEmpty() {
		return -1 // Indicates empty queue
	}
	item := q.items[0]
	q.items = q.items[1:]
	return item
}

// IsEmpty method to check if the queue is empty
func (q *Queue) isEmpty() bool {
	return len(q.items) == 0
}

func main() {
	// Create an instance of the queue
	myQueue := Queue{}

	// Enqueue elements to the queue
	myQueue.enqueue(10)
	myQueue.enqueue(20)
	myQueue.enqueue(30)
	myQueue.enqueue(40)
	myQueue.enqueue(50)

	// Access and print the elements of the queue
	fmt.Println("Elements in the Queue:")
	for !myQueue.isEmpty() {
		fmt.Printf("Dequeued Element: %v\n", myQueue.dequeue())
	}
}
