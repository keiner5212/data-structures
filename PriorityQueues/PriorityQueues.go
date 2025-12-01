package main

import (
	"fmt"
	"time"
	"unsafe"
)

// Demonstrates priority queue operations: insert and extract_min.
// Inserts values and extracts them in ascending order.
type PriorityQueue struct {
	heap []int
}

func (pq *PriorityQueue) insert(val int) {
	pq.heap = append(pq.heap, val)
	pq.heapifyUp(len(pq.heap) - 1)
}

func (pq *PriorityQueue) extractMin() int {
	if len(pq.heap) == 0 {
		panic("extract from empty priority queue")
	}
	minVal := pq.heap[0]
	lastVal := pq.heap[len(pq.heap)-1]
	pq.heap = pq.heap[:len(pq.heap)-1]
	if len(pq.heap) > 0 {
		pq.heap[0] = lastVal
		pq.heapifyDown(0)
	}
	return minVal
}

func (pq *PriorityQueue) peek() int {
	if len(pq.heap) == 0 {
		panic("peek from empty priority queue")
	}
	return pq.heap[0]
}

func (pq *PriorityQueue) isEmpty() bool {
	return len(pq.heap) == 0
}

func (pq *PriorityQueue) heapifyUp(index int) {
	for index > 0 {
		parent := (index - 1) / 2
		if pq.heap[index] < pq.heap[parent] {
			pq.heap[index], pq.heap[parent] = pq.heap[parent], pq.heap[index]
			index = parent
		} else {
			break
		}
	}
}

func (pq *PriorityQueue) heapifyDown(index int) {
	size := len(pq.heap)
	for {
		left := 2*index + 1
		right := 2*index + 2
		smallest := index
		if left < size && pq.heap[left] < pq.heap[smallest] {
			smallest = left
		}
		if right < size && pq.heap[right] < pq.heap[smallest] {
			smallest = right
		}
		if smallest != index {
			pq.heap[index], pq.heap[smallest] = pq.heap[smallest], pq.heap[index]
			index = smallest
		} else {
			break
		}
	}
}

func main() {
	startTime := time.Now()

	pq := &PriorityQueue{}
	values := []int{3, 1, 4, 1, 5, 9, 2, 6}

	for _, val := range values {
		pq.insert(val)
	}

	for !pq.isEmpty() {
		fmt.Println(pq.extractMin())
	}

	elapsed := time.Since(startTime)

	// Memory calculation
	memoryUsed := unsafe.Sizeof(*pq) + uintptr(cap(pq.heap))*unsafe.Sizeof(0)

	// Performance statistics
	fmt.Println("\n--- Performance Statistics ---")
	fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
	fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
	fmt.Println("\nTime Complexity:")
	fmt.Println("  - Insert: O(log n)")
	fmt.Println("  - Extract_min: O(log n)")
	fmt.Println("  - Peek: O(1)")
}
