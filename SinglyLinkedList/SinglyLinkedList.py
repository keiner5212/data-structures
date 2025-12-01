import time
import sys


class Node:
    """Node for singly linked list."""
    
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    """Singly linked list implementation with basic operations."""
    
    def __init__(self):
        self.head = None
        self.size = 0
    
    def is_empty(self):
        """Check if list is empty. O(1) operation."""
        return self.head is None
    
    def get_size(self):
        """Return number of elements in list. O(1) operation."""
        return self.size
    
    def insert_at_beginning(self, data):
        """Insert element at the beginning of the list. O(1) operation."""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        self.size += 1
    
    def insert_at_end(self, data):
        """Insert element at the end of the list. O(n) operation."""
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        self.size += 1
    
    def insert_at_position(self, data, position):
        """Insert element at specified position. O(n) operation."""
        if position < 0 or position > self.size:
            raise IndexError("Invalid position")
        
        if position == 0:
            self.insert_at_beginning(data)
            return
        
        new_node = Node(data)
        current = self.head
        for _ in range(position - 1):
            current = current.next
        
        new_node.next = current.next
        current.next = new_node
        self.size += 1
    
    def delete_from_beginning(self):
        """Delete element from the beginning of the list. O(1) operation."""
        if self.is_empty():
            return None
        
        deleted_data = self.head.data
        self.head = self.head.next
        self.size -= 1
        return deleted_data
    
    def delete_from_end(self):
        """Delete element from the end of the list. O(n) operation."""
        if self.is_empty():
            return None
        
        if self.head.next is None:
            deleted_data = self.head.data
            self.head = None
            self.size -= 1
            return deleted_data
        
        current = self.head
        while current.next.next:
            current = current.next
        
        deleted_data = current.next.data
        current.next = None
        self.size -= 1
        return deleted_data
    
    def delete_by_value(self, value):
        """Delete first occurrence of value. O(n) operation."""
        if self.is_empty():
            return False
        
        if self.head.data == value:
            self.head = self.head.next
            self.size -= 1
            return True
        
        current = self.head
        while current.next and current.next.data != value:
            current = current.next
        
        if current.next:
            current.next = current.next.next
            self.size -= 1
            return True
        
        return False
    
    def search(self, value):
        """Search for value in the list. O(n) operation."""
        current = self.head
        position = 0
        while current:
            if current.data == value:
                return position
            current = current.next
            position += 1
        return -1
    
    def display(self):
        """Display all elements in the list."""
        if self.is_empty():
            print("List is empty")
            return
        
        current = self.head
        elements = []
        while current:
            elements.append(str(current.data))
            current = current.next
        print(" -> ".join(elements))


def main():
    """
    Demonstrates singly linked list operations.
    Performs insertions, deletions, and searches on the list.
    """
    start_time = time.time()
    
    # Create linked list instance
    sll = SinglyLinkedList()
    
    # Insert elements
    sll.insert_at_end(10)
    sll.insert_at_end(20)
    sll.insert_at_beginning(5)
    sll.insert_at_position(15, 2)
    
    print("List after insertions:")
    sll.display()
    
    # Calculate memory usage
    memory_bytes = sys.getsizeof(sll)
    current = sll.head
    while current:
        memory_bytes += sys.getsizeof(current)
        current = current.next
    
    # Search operations
    search_values = [15, 25]
    print("\nSearch results:")
    for value in search_values:
        position = sll.search(value)
        if position != -1:
            print(f"Value {value} found at position {position}")
        else:
            print(f"Value {value} not found")
    
    # Delete operations
    sll.delete_by_value(20)
    print("\nList after deleting 20:")
    sll.display()
    
    sll.delete_from_beginning()
    print("\nList after deleting from beginning:")
    sll.display()
    
    sll.delete_from_end()
    print("\nList after deleting from end:")
    sll.display()
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print(f"Final list size: {sll.get_size()}")
    print("\nTime Complexity:")
    print("  - Insert at beginning: O(1)")
    print("  - Insert at end: O(n)")
    print("  - Insert at position: O(n)")
    print("  - Delete from beginning: O(1)")
    print("  - Delete from end: O(n)")
    print("  - Delete by value: O(n)")
    print("  - Search: O(n)")
    print("  - Get size: O(1)")


if __name__ == "__main__":
    main()