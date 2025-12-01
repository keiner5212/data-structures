package Queues;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Demonstrates queue operations with FIFO (First In First Out) behavior.
 * Uses Queue interface with LinkedList implementation.
 * Enqueues 5 integers and dequeues them to show ordering.
 */
public class Queues {

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Create queue instance using LinkedList
        Queue<Integer> myQueue = new LinkedList<>();

        // Enqueue elements
        myQueue.offer(10);
        myQueue.offer(20);
        myQueue.offer(30);
        myQueue.offer(40);
        myQueue.offer(50);

        // Dequeue and print elements
        System.out.println("Elements in the Queue:");
        while (!myQueue.isEmpty()) {
            System.out.println("Dequeued Element: " + myQueue.poll());
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
