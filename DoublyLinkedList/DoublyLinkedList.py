"""
Doubly linked list implementation with basic operations.
Each node contains data and references to both previous and next nodes.
"""


class Node:
    """Node class for doubly linked list."""
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    """Doubly linked list with comprehensive operations."""

    def __init__(self):
        self.head = None
        self.tail = None
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
        if self.is_empty():
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def insert_at_end(self, data):
        """Insert element at the end of the list. O(1) operation."""
        new_node = Node(data)
        if self.is_empty():
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def insert_at_position(self, data, position):
        """Insert element at specified position. O(n) operation."""
        if position < 0 or position > self.size:
            raise ValueError("Invalid position")

        if position == 0:
            self.insert_at_beginning(data)
            return

        if position == self.size:
            self.insert_at_end(data)
            return

        new_node = Node(data)
        current = self.head
        for _ in range(position - 1):
            current = current.next

        new_node.next = current.next
        new_node.prev = current
        current.next.prev = new_node
        current.next = new_node
        self.size += 1

    def delete_from_beginning(self):
        """Delete element from the beginning of the list. O(1) operation."""
        if self.is_empty():
            return None

        deleted_data = self.head.data
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return deleted_data

    def delete_from_end(self):
        """Delete element from the end of the list. O(1) operation."""
        if self.is_empty():
            return None

        deleted_data = self.tail.data
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return deleted_data

    def delete_by_value(self, value):
        """Delete first occurrence of value. O(n) operation."""
        if self.is_empty():
            return False

        current = self.head
        while current:
            if current.data == value:
                if current == self.head:
                    self.delete_from_beginning()
                elif current == self.tail:
                    self.delete_from_end()
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                    self.size -= 1
                return True
            current = current.next
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

    def display_forward(self):
        """Display all elements from head to tail."""
        if self.is_empty():
            print("List is empty")
            return

        current = self.head
        elements = []
        while current:
            elements.append(str(current.data))
            current = current.next
        print(" -> ".join(elements))

    def display_backward(self):
        """Display all elements from tail to head."""
        if self.is_empty():
            print("List is empty")
            return

        current = self.tail
        elements = []
        while current:
            elements.append(str(current.data))
            current = current.prev
        print(" <- ".join(elements))


def main():
    """Demonstrates doubly linked list operations."""
    import time
    import sys

    start_time = time.time()
    memory_before = sys.getsizeof([])  # Approximate baseline

    # Create doubly linked list instance
    dll = DoublyLinkedList()

    # Insert elements
    dll.insert_at_end(10)
    dll.insert_at_end(20)
    dll.insert_at_beginning(5)
    dll.insert_at_position(15, 2)

    print("List after insertions (forward):")
    dll.display_forward()

    print("\nList after insertions (backward):")
    dll.display_backward()

    # Search operations
    search_values = [15, 25]
    print("\nSearch results:")
    for value in search_values:
        position = dll.search(value)
        if position != -1:
            print(f"Value {value} found at position {position}")
        else:
            print(f"Value {value} not found")

    # Delete operations
    dll.delete_by_value(20)
    print("\nList after deleting 20 (forward):")
    dll.display_forward()

    dll.delete_from_beginning()
    print("\nList after deleting from beginning (forward):")
    dll.display_forward()

    dll.delete_from_end()
    print("\nList after deleting from end (forward):")
    dll.display_forward()

    end_time = time.time()
    memory_after = sys.getsizeof([])  # Approximate after

    # Performance statistics
    execution_time = (end_time - start_time) * 1000  # Convert to ms
    memory_used = memory_after - memory_before

    print("\n--- Performance Statistics ---")
    print(f"Execution time: {execution_time:.4f} ms")
    print(f"Memory usage: {memory_used if memory_used > 0 else 'negligible'} bytes")
    print(f"Final list size: {dll.get_size()}")
    print("\nTime Complexity:")
    print("  - Insert at beginning: O(1)")
    print("  - Insert at end: O(1)")
    print("  - Insert at position: O(n)")
    print("  - Delete from beginning: O(1)")
    print("  - Delete from end: O(1)")
    print("  - Delete by value: O(n)")
    print("  - Search: O(n)")
    print("  - Get size: O(1)")


if __name__ == "__main__":
    main()