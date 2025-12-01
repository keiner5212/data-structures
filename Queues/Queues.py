import time
import sys


class Queue:
    """Queue implementation using list with FIFO (First In First Out) operations."""
    
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        """Add element to the rear of the queue. O(1) operation."""
        self.items.append(item)

    def dequeue(self):
        """Remove and return front element from the queue. O(n) operation."""
        if self.is_empty():
            return None
        return self.items.pop(0)

    def is_empty(self):
        """Check if queue is empty. O(1) operation."""
        return len(self.items) == 0
    
    def peek(self):
        """Return front element without removing it. O(1) operation."""
        if self.is_empty():
            return None
        return self.items[0]
    
    def size(self):
        """Return number of elements in queue. O(1) operation."""
        return len(self.items)


def main():
    """
    Demonstrates queue operations with FIFO behavior.
    Enqueues 5 integers and dequeues them to show ordering.
    """
    start_time = time.time()
    
    # Create queue instance
    my_queue = Queue()
    
    # Enqueue elements
    my_queue.enqueue(10)
    my_queue.enqueue(20)
    my_queue.enqueue(30)
    my_queue.enqueue(40)
    my_queue.enqueue(50)
    
    # Calculate memory usage
    memory_bytes = sys.getsizeof(my_queue.items) + sum(sys.getsizeof(item) for item in my_queue.items)

    # Dequeue and print elements
    print("Elements in the Queue:")
    while not my_queue.is_empty():
        print(f"Dequeued Element: {my_queue.dequeue()}")
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity:")
    print("  - Enqueue: O(1)")
    print("  - Dequeue: O(n)")
    print("  - Peek: O(1)")
    print("  - IsEmpty: O(1)")


if __name__ == "__main__":
    main()
