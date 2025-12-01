import time
import sys
import random


class SkipListNode:
    """Node for SkipList with multiple forward pointers."""
    
    def __init__(self, key, level):
        self.key = key
        self.forward = [None] * (level + 1)


class SkipList:
    """SkipList implementation with probabilistic level assignment."""
    
    def __init__(self, max_level=16, p=0.5):
        self.max_level = max_level
        self.p = p
        self.header = self._create_node(float('-inf'), max_level)
        self.level = 0
    
    def _create_node(self, key, level):
        """Create a new node with specified level."""
        return SkipListNode(key, level)
    
    def _random_level(self):
        """Generate random level for new node."""
        level = 0
        while random.random() < self.p and level < self.max_level:
            level += 1
        return level
    
    def search(self, key):
        """Search for key in SkipList. O(log n) average time."""
        current = self.header
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
        
        current = current.forward[0]
        if current and current.key == key:
            return current.key
        return None
    
    def insert(self, key):
        """Insert key into SkipList. O(log n) average time."""
        update = [None] * (self.max_level + 1)
        current = self.header
        
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        
        current = current.forward[0]
        
        if not current or current.key != key:
            new_level = self._random_level()
            
            if new_level > self.level:
                for i in range(self.level + 1, new_level + 1):
                    update[i] = self.header
                self.level = new_level
            
            new_node = self._create_node(key, new_level)
            
            for i in range(new_level + 1):
                new_node.forward[i] = update[i].forward[i]
                update[i].forward[i] = new_node
    
    def delete(self, key):
        """Delete key from SkipList. O(log n) average time."""
        update = [None] * (self.max_level + 1)
        current = self.header
        
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        
        current = current.forward[0]
        
        if current and current.key == key:
            for i in range(self.level + 1):
                if update[i].forward[i] != current:
                    break
                update[i].forward[i] = current.forward[i]
            
            while self.level > 0 and not self.header.forward[self.level]:
                self.level -= 1
    
    def display(self):
        """Display SkipList structure."""
        print("SkipList structure:")
        for level in range(self.level, -1, -1):
            current = self.header.forward[level]
            level_str = f"Level {level}: "
            while current:
                level_str += f"{current.key} -> "
                current = current.forward[level]
            level_str += "None"
            print(level_str)


def main():
    """
    Demonstrates SkipList operations with probabilistic balancing.
    Inserts 10 elements, searches for values, and displays structure.
    """
    start_time = time.time()
    
    # Create SkipList instance
    skip_list = SkipList()
    
    # Insert elements
    elements = [3, 6, 7, 9, 12, 19, 17, 26, 21, 25]
    for elem in elements:
        skip_list.insert(elem)
    
    # Calculate memory usage (approximate)
    memory_bytes = sys.getsizeof(skip_list)
    
    # Display structure
    skip_list.display()
    
    # Search operations
    search_keys = [19, 15, 21]
    print("\nSearch results:")
    for key in search_keys:
        result = skip_list.search(key)
        print(f"Search for {key}: {'Found' if result else 'Not found'}")
    
    # Delete operation
    skip_list.delete(17)
    print("\nAfter deleting 17:")
    skip_list.display()
    
    end_time = time.time()
    
    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity (Average):")
    print("  - Search: O(log n)")
    print("  - Insert: O(log n)")
    print("  - Delete: O(log n)")
    print("  - Space: O(n)")


if __name__ == "__main__":
    main()