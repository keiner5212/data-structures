#include <iostream>
#include <stack>
#include <chrono>
#include <iomanip>

/**
 * Demonstrates stack operations with LIFO (Last In First Out) behavior.
 * Uses std::stack container adapter.
 * Pushes 5 integers and pops them to show reverse ordering.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Create stack instance
    std::stack<int> myStack;

    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    
    // Calculate memory (approximate for 5 integers)
    size_t memoryUsed = sizeof(int) * 5 + sizeof(std::stack<int>);

    // Pop and print elements
    std::cout << "Elements in the Stack:" << std::endl;
    while (!myStack.empty()) {
        std::cout << "Popped Element: " << myStack.top() << std::endl;
        myStack.pop();
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
