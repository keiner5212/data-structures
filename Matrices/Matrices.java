package Matrices;

/**
 * Demonstrates matrix declaration and element access.
 * Creates a 2x3 matrix and prints all elements in row-column format.
 */
public class Matrices {
    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Initialize 2x3 matrix
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6}
        };

        // Print matrix elements
        System.out.println("Result Matrix:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
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
        System.out.println("  - Search: O(m*n)");
        System.out.println("  - Insertion (row/col): O(m*n)");
        System.out.println("  - Traversal: O(m*n)");
    }
}
