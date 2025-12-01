#include <iostream>
#include <chrono>
#include <iomanip>

/**
 * Node structure for linked list implementation of stack.
 */
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

/**
 * Stack implementation using linked list (without STL).
 * Provides O(1) push and pop operations.
 */
class Stack {
private:
    Node* top;
    size_t count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    /**
     * Add element to the top of the stack. O(1) operation.
     */
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    /**
     * Remove and return top element from the stack. O(1) operation.
     */
    int pop() {
        if (isEmpty()) {
            std::cerr << "Error: Attempting to pop from an empty stack." << std::endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return value;
    }

    /**
     * Check if stack is empty. O(1) operation.
     */
    bool isEmpty() const {
        return top == nullptr;
    }

    /**
     * Return top element without removing it. O(1) operation.
     */
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    /**
     * Return number of elements in stack. O(1) operation.
     */
    size_t size() const {
        return count;
    }
};

/**
 * Demonstrates stack operations using custom linked list implementation.
 * Pushes 5 integers and pops them to show LIFO ordering.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Create stack instance
    Stack myStack;

    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    
    // Calculate memory (5 nodes + overhead)
    size_t memoryUsed = sizeof(Stack) + (sizeof(Node) * 5);

    // Pop and print elements
    std::cout << "Elements in the Stack:" << std::endl;
    while (!myStack.isEmpty()) {
        std::cout << "Popped Element: " << myStack.pop() << std::endl;
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: " << memoryUsed << " bytes" << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Push: O(1)" << std::endl;
    std::cout << "  - Pop: O(1)" << std::endl;
    std::cout << "  - Peek: O(1)" << std::endl;
    std::cout << "  - IsEmpty: O(1)" << std::endl;

    return 0;
}
