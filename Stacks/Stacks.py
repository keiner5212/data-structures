import time
import sys


class Stack:
    """Stack implementation using list with LIFO (Last In First Out) operations."""
    
    def __init__(self):
        self.items = []

    def push(self, item):
        """Add element to the top of the stack. O(1) operation."""
        self.items.append(item)

    def pop(self):
        """Remove and return top element from the stack. O(1) operation."""
        if self.is_empty():
            return None
        return self.items.pop()

    def is_empty(self):
        """Check if stack is empty. O(1) operation."""
        return len(self.items) == 0
    
    def peek(self):
        """Return top element without removing it. O(1) operation."""
        if self.is_empty():
            return None
        return self.items[-1]
    
    def size(self):
        """Return number of elements in stack. O(1) operation."""
        return len(self.items)


def main():
    """
    Demonstrates stack operations with LIFO behavior.
    Pushes 5 integers and pops them to show reverse ordering.
    """
    start_time = time.time()
    
    # Create stack instance
    my_stack = Stack()
    
    # Push elements
    my_stack.push(10)
    my_stack.push(20)
    my_stack.push(30)
    my_stack.push(40)
    my_stack.push(50)
    
    # Calculate memory usage
    memory_bytes = sys.getsizeof(my_stack.items) + sum(sys.getsizeof(item) for item in my_stack.items)

    # Pop and print elements
    print("Elements in the Stack:")
    while not my_stack.is_empty():
        print(f"Popped Element: {my_stack.pop()}")
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity:")
    print("  - Push: O(1)")
    print("  - Pop: O(1)")
    print("  - Peek: O(1)")
    print("  - IsEmpty: O(1)")


if __name__ == "__main__":
    main()