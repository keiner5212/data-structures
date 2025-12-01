package Queues;

/**
 * Demonstrates queue operations using custom linked list implementation.
 * Provides O(1) enqueue and dequeue operations without using standard library.
 * Enqueues 5 integers and dequeues them to show FIFO ordering.
 */
public class QueuesWithoutLibrary {

    /**
     * Node class for linked list implementation.
     */
    private static class Node {
        int data;
        Node next;

        Node(int value) {
            data = value;
            next = null;
        }
    }

    /**
     * Queue implementation using linked list.
     */
    private static class CustomQueue {
        private Node front;
        private Node rear;
        private int count;

        public CustomQueue() {
            front = rear = null;
            count = 0;
        }

        /**
         * Add element to the rear of the queue. O(1) operation.
         */
        public void enqueue(int value) {
            Node newNode = new Node(value);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear.next = newNode;
                rear = newNode;
            }
            count++;
        }

        /**
         * Remove and return front element from the queue. O(1) operation.
         */
        public int dequeue() {
            if (isEmpty()) {
                System.err.println("Error: Attempting to dequeue from an empty queue.");
                return -1;
            }

            int value = front.data;
            front = front.next;

            if (front == null) {
                rear = null;
            }
            count--;
            return value;
        }

        /**
         * Check if queue is empty. O(1) operation.
         */
        public boolean isEmpty() {
            return front == null;
        }

        /**
         * Return front element without removing it. O(1) operation.
         */
        public int peek() {
            if (isEmpty()) {
                System.err.println("Error: Queue is empty.");
                return -1;
            }
            return front.data;
        }

        /**
         * Return number of elements in queue. O(1) operation.
         */
        public int size() {
            return count;
        }
    }

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Create queue instance
        CustomQueue myQueue = new CustomQueue();

        // Enqueue elements
        myQueue.enqueue(10);
        myQueue.enqueue(20);
        myQueue.enqueue(30);
        myQueue.enqueue(40);
        myQueue.enqueue(50);

        // Dequeue and print elements
        System.out.println("Elements in the Queue:");
        while (!myQueue.isEmpty()) {
            System.out.println("Dequeued Element: " + myQueue.dequeue());
        }
        
        long endTime = System.nanoTime();
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;
        
        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.printf("Execution time: %.4f ms%n", (endTime - startTime) / 1_000_000.0);
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("\nTime Complexity:");
        System.out.println("  - Enqueue: O(1)");
        System.out.println("  - Dequeue: O(1)");
        System.out.println("  - Peek: O(1)");
        System.out.println("  - IsEmpty: O(1)");
    }
}
