package Arrays;

/**
 * Demonstrates array declaration, initialization, and element access.
 * Creates an array with 5 integers and prints each element with its index.
 */
public class Arrays {
    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Initialize array with 5 elements
        int[] myArray = {10, 20, 30, 40, 50};

        // Iterate through array and print each element
        for (int i = 0; i < myArray.length; i++) {
            System.out.println("Element " + i + ": " + myArray[i]);
        }
        
        long endTime = System.nanoTime();
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;
        
        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.printf("Execution time: %.4f ms%n", (endTime - startTime) / 1_000_000.0);
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("\nTime Complexity:");
        System.out.println("  - Access: O(1)");
        System.out.println("  - Search: O(n)");
        System.out.println("  - Insertion: O(n)");
        System.out.println("  - Deletion: O(n)");
    }
}
