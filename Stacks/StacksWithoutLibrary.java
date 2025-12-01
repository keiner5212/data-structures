package Stacks;

/**
 * Demonstrates stack operations using custom ArrayList implementation.
 * Provides O(1) push and pop operations.
 * Pushes 5 integers and pops them to show LIFO ordering.
 */
public class StacksWithoutLibrary {

    /**
     * Stack implementation using ArrayList.
     */
    private static class Stack {
        private java.util.ArrayList<Integer> items;
        private int count;

        public Stack() {
            this.items = new java.util.ArrayList<>();
            this.count = 0;
        }

        /**
         * Add element to the top of the stack. O(1) operation.
         */
        public void push(int item) {
            items.add(item);
            count++;
        }

        /**
         * Remove and return top element from the stack. O(1) operation.
         */
        public int pop() {
            if (isEmpty()) {
                System.err.println("Error: Attempting to pop from an empty stack.");
                return -1;
            }
            int item = items.get(items.size() - 1);
            items.remove(items.size() - 1);
            count--;
            return item;
        }

        /**
         * Check if stack is empty. O(1) operation.
         */
        public boolean isEmpty() {
            return items.isEmpty();
        }

        /**
         * Return top element without removing it. O(1) operation.
         */
        public int peek() {
            if (isEmpty()) {
                System.err.println("Error: Stack is empty.");
                return -1;
            }
            return items.get(items.size() - 1);
        }

        /**
         * Return number of elements in stack. O(1) operation.
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
        
        // Create stack instance
        Stack myStack = new Stack();

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
