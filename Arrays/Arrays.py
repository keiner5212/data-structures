import time
import sys


def main():
    """
    Demonstrates array declaration, initialization, and element access.
    Creates an array with 5 integers and prints each element with its index.
    """
    start_time = time.time()
    
    # Initialize array with 5 elements
    my_array = [10, 20, 30, 40, 50]
    
    # Memory calculation
    memory_bytes = sys.getsizeof(my_array) + sum(sys.getsizeof(item) for item in my_array)

    # Iterate through array and print each element
    for i in range(len(my_array)):
        print(f"Element {i}: {my_array[i]}")
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity:")
    print("  - Access: O(1)")
    print("  - Search: O(n)")
    print("  - Insertion: O(n)")
    print("  - Deletion: O(n)")


if __name__ == "__main__":
    main()
