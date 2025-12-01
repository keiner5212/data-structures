#include <iostream>
#include <queue>
#include <chrono>
#include <iomanip>

/**
 * Demonstrates queue operations with FIFO (First In First Out) behavior.
 * Uses std::queue container adapter.
 * Enqueues 5 integers and dequeues them to show ordering.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Create queue instance
    std::queue<int> myQueue;

    // Enqueue elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    
    // Calculate memory (approximate for 5 integers)
    size_t memoryUsed = sizeof(int) * 5 + sizeof(std::queue<int>);

    // Dequeue and print elements
    std::cout << "Elements in the Queue:" << std::endl;
    while (!myQueue.empty()) {
        std::cout << "Dequeued Element: " << myQueue.front() << std::endl;
        myQueue.pop();
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
