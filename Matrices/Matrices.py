import time
import sys


def main():
    """
    Demonstrates matrix declaration and element access.
    Creates a 2x3 matrix and prints all elements in row-column format.
    """
    start_time = time.time()
    
    # Initialize 2x3 matrix
    matrix = [[1, 2, 3], [4, 5, 6]]
    
    # Memory calculation
    memory_bytes = sys.getsizeof(matrix) + sum(sys.getsizeof(row) + sum(sys.getsizeof(item) for item in row) for row in matrix)

    # Print matrix elements
    print("Result Matrix:")
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=" ")
        print()
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity:")
    print("  - Access: O(1)")
    print("  - Search: O(m*n)")
    print("  - Insertion (row/col): O(m*n)")
    print("  - Traversal: O(m*n)")


if __name__ == "__main__":
    main()
