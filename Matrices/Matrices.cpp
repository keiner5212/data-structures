#include <iostream>
#include <chrono>
#include <iomanip>

/**
 * Demonstrates matrix declaration and element access.
 * Creates a 2x3 matrix and prints all elements in row-column format.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Initialize 2x3 matrix
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    size_t memoryUsed = sizeof(matrix);

    // Print matrix elements
    std::cout << "Result Matrix:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
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
    std::cout << "  - Search: O(m*n)" << std::endl;
    std::cout << "  - Insertion (row/col): O(m*n)" << std::endl;
    std::cout << "  - Traversal: O(m*n)" << std::endl;

    return 0;
}
