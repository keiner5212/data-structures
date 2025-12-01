#include <iostream>
#include <chrono>
#include <iomanip>

/**
 * Node structure for linked list implementation of queue.
 */
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/**
 * Queue implementation using linked list (without STL).
 * Provides O(1) enqueue and dequeue operations.
 */
class Queue {
private:
    Node* front;
    Node* rear;
    size_t count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    /**
     * Add element to the rear of the queue. O(1) operation.
     */
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    /**
     * Remove and return front element from the queue. O(1) operation.
     */
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Error: Attempting to dequeue from an empty queue." << std::endl;
            return -1;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
        count--;
        return value;
    }

    /**
     * Check if queue is empty. O(1) operation.
     */
    bool isEmpty() const {
        return front == nullptr;
    }

    /**
     * Return front element without removing it. O(1) operation.
     */
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty." << std::endl;
            return -1;
        }
        return front->data;
    }

    /**
     * Return number of elements in queue. O(1) operation.
     */
    size_t size() const {
        return count;
    }
};

/**
 * Demonstrates queue operations using custom linked list implementation.
 * Enqueues 5 integers and dequeues them to show FIFO ordering.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Create queue instance
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    
    // Calculate memory (5 nodes + overhead)
    size_t memoryUsed = sizeof(Queue) + (sizeof(Node) * 5);

    // Dequeue and print elements
    std::cout << "Elements in the Queue:" << std::endl;
    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued Element: " << myQueue.dequeue() << std::endl;
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: " << memoryUsed << " bytes" << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Enqueue: O(1)" << std::endl;
    std::cout << "  - Dequeue: O(1)" << std::endl;
    std::cout << "  - Peek: O(1)" << std::endl;
    std::cout << "  - IsEmpty: O(1)" << std::endl;

    return 0;
}
