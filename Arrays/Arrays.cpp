#include <iostream>
#include <chrono>
#include <iomanip>

/**
 * Demonstrates array declaration, initialization, and element access.
 * Creates an array with 5 integers and prints each element with its index.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Initialize array with 5 elements
    int myArray[5] = {10, 20, 30, 40, 50};
    
    size_t memoryUsed = sizeof(myArray);

    // Iterate through array and print each element
    for (int i = 0; i < 5; i++) {
        std::cout << "Element " << i << ": " << myArray[i] << std::endl;
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: " << memoryUsed << " bytes" << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Access: O(1)" << std::endl;
    std::cout << "  - Search: O(n)" << std::endl;
    std::cout << "  - Insertion: O(n)" << std::endl;
    std::cout << "  - Deletion: O(n)" << std::endl;

    return 0;
}
