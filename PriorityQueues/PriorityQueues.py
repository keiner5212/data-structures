import time
import sys


class PriorityQueue:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        self.heap.append(val)
        self._heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if not self.heap:
            raise IndexError("extract from empty priority queue")
        min_val = self.heap[0]
        last_val = self.heap.pop()
        if self.heap:
            self.heap[0] = last_val
            self._heapify_down(0)
        return min_val

    def peek(self):
        if not self.heap:
            raise IndexError("peek from empty priority queue")
        return self.heap[0]

    def is_empty(self):
        return len(self.heap) == 0

    def _heapify_up(self, index):
        while index > 0:
            parent = (index - 1) // 2
            if self.heap[index] < self.heap[parent]:
                self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
                index = parent
            else:
                break

    def _heapify_down(self, index):
        size = len(self.heap)
        while True:
            left = 2 * index + 1
            right = 2 * index + 2
            smallest = index
            if left < size and self.heap[left] < self.heap[smallest]:
                smallest = left
            if right < size and self.heap[right] < self.heap[smallest]:
                smallest = right
            if smallest != index:
                self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
                index = smallest
            else:
                break


def main():
    """
    Demonstrates priority queue operations: insert and extract_min.
    Inserts values and extracts them in ascending order.
    """
    start_time = time.time()

    pq = PriorityQueue()
    values = [3, 1, 4, 1, 5, 9, 2, 6]

    for val in values:
        pq.insert(val)

    extracted = []
    while not pq.is_empty():
        extracted.append(pq.extract_min())

    for val in extracted:
        print(val)

    end_time = time.time()

    # Memory calculation
    memory_bytes = sys.getsizeof(pq) + sys.getsizeof(pq.heap) + sum(sys.getsizeof(item) for item in pq.heap)

    # Performance statistics
    print("\n--- Performance Statistics ---")
    print(f"Execution time: {(end_time - start_time) * 1000:.4f} ms")
    print(f"Memory usage: {memory_bytes} bytes")
    print("\nTime Complexity:")
    print("  - Insert: O(log n)")
    print("  - Extract_min: O(log n)")
    print("  - Peek: O(1)")


if __name__ == "__main__":
    main()
