package PriorityQueues;

/**
 * Demonstrates priority queue operations: insert and extract_min.
 * Inserts values and extracts them in ascending order.
 */
public class PriorityQueues {
    static class PriorityQueueImpl {
        private int[] heap;
        private int size;
        private static final int INITIAL_CAPACITY = 10;

        public PriorityQueueImpl() {
            heap = new int[INITIAL_CAPACITY];
            size = 0;
        }

        public void insert(int val) {
            if (size == heap.length) {
                resize();
            }
            heap[size] = val;
            heapifyUp(size);
            size++;
        }

        public int extractMin() {
            if (size == 0) {
                throw new IllegalStateException("extract from empty priority queue");
            }
            int minVal = heap[0];
            int lastVal = heap[--size];
            if (size > 0) {
                heap[0] = lastVal;
                heapifyDown(0);
            }
            return minVal;
        }

        public int peek() {
            if (size == 0) {
                throw new IllegalStateException("peek from empty priority queue");
            }
            return heap[0];
        }

        public boolean isEmpty() {
            return size == 0;
        }

        private void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] < heap[parent]) {
                    swap(index, parent);
                    index = parent;
                } else {
                    break;
                }
            }
        }

        private void heapifyDown(int index) {
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
                    swap(index, smallest);
                    index = smallest;
                } else {
                    break;
                }
            }
        }

        private void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        private void resize() {
            int[] newHeap = new int[heap.length * 2];
            System.arraycopy(heap, 0, newHeap, 0, heap.length);
            heap = newHeap;
        }
    }

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();

        PriorityQueueImpl pq = new PriorityQueueImpl();
        int[] values = {3, 1, 4, 1, 5, 9, 2, 6};

        for (int val : values) {
            pq.insert(val);
        }

        while (!pq.isEmpty()) {
            System.out.println(pq.extractMin());
        }

        long endTime = System.nanoTime();
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;

        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.printf("Execution time: %.4f ms%n", (endTime - startTime) / 1_000_000.0);
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("\nTime Complexity:");
        System.out.println("  - Insert: O(log n)");
        System.out.println("  - Extract_min: O(log n)");
        System.out.println("  - Peek: O(1)");
    }
}
