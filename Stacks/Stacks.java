package Stacks;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Demonstrates stack operations with LIFO (Last In First Out) behavior.
 * Uses Deque interface with ArrayDeque implementation.
 * Pushes 5 integers and pops them to show reverse ordering.
 */
public class Stacks {

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Create stack instance using ArrayDeque
        Deque<Integer> myStack = new ArrayDeque<>();

        // Push elements
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40);
        myStack.push(50);

        // Pop and print elements
        System.out.println("Elements in the Stack:");
        while (!myStack.isEmpty()) {
            System.out.println("Popped Element: " + myStack.pop());
        }
        
        long endTime = System.nanoTime();
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;
        
        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.printf("Execution time: %.4f ms%n", (endTime - startTime) / 1_000_000.0);
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("\nTime Complexity:");
        System.out.println("  - Push: O(1)");
        System.out.println("  - Pop: O(1)");
        System.out.println("  - Peek: O(1)");
        System.out.println("  - IsEmpty: O(1)");
    }
}
