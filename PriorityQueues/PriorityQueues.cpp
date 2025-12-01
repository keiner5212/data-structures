#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

/**
 * Demonstrates priority queue operations: insert and extract_min.
 * Inserts values and extracts them in ascending order.
 */
class PriorityQueue {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw std::runtime_error("extract from empty priority queue");
        }
        int minVal = heap[0];
        int lastVal = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap[0] = lastVal;
            heapifyDown(0);
        }
        return minVal;
    }

    int peek() {
        if (heap.empty()) {
            throw std::runtime_error("peek from empty priority queue");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    PriorityQueue pq;
    std::vector<int> values = {3, 1, 4, 1, 5, 9, 2, 6};

    for (int val : values) {
        pq.insert(val);
    }

    while (!pq.isEmpty()) {
        std::cout << pq.extractMin() << std::endl;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    // Memory calculation
    size_t memoryUsed = sizeof(PriorityQueue);

    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: " << memoryUsed << " bytes" << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Insert: O(log n)" << std::endl;
    std::cout << "  - Extract_min: O(log n)" << std::endl;
    std::cout << "  - Peek: O(1)" << std::endl;

    return 0;
}
