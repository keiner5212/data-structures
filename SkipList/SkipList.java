package SkipList;

import java.util.Random;

/**
 * SkipList implementation with probabilistic level assignment.
 * Provides O(log n) average time for search, insert, and delete operations.
 * Demonstrates SkipList operations with probabilistic balancing.
 * Inserts 10 elements, searches for values, and displays structure.
 */
public class SkipList {

    private static class SkipListNode {
        int key;
        SkipListNode[] forward;

        SkipListNode(int key, int level) {
            this.key = key;
            this.forward = new SkipListNode[level + 1];
        }
    }

    private static class SkipListImpl {
        private static final int MAX_LEVEL = 16;
        private static final double P = 0.5;
        private SkipListNode header;
        private int level;
        private Random random;

        public SkipListImpl() {
            this.header = new SkipListNode(Integer.MIN_VALUE, MAX_LEVEL);
            this.level = 0;
            this.random = new Random();
        }

        private int randomLevel() {
            int level = 0;
            while (random.nextDouble() < P && level < MAX_LEVEL) {
                level++;
            }
            return level;
        }

        /**
         * Search for key in SkipList. O(log n) average time.
         */
        public Integer search(int key) {
            SkipListNode current = header;
            for (int i = level; i >= 0; i--) {
                while (current.forward[i] != null && current.forward[i].key < key) {
                    current = current.forward[i];
                }
            }

            current = current.forward[0];
            if (current != null && current.key == key) {
                return current.key;
            }
            return null;
        }

        /**
         * Insert key into SkipList. O(log n) average time.
         */
        public void insert(int key) {
            SkipListNode[] update = new SkipListNode[MAX_LEVEL + 1];
            SkipListNode current = header;

            for (int i = level; i >= 0; i--) {
                while (current.forward[i] != null && current.forward[i].key < key) {
                    current = current.forward[i];
                }
                update[i] = current;
            }

            current = current.forward[0];

            if (current == null || current.key != key) {
                int newLevel = randomLevel();

                if (newLevel > level) {
                    for (int i = level + 1; i <= newLevel; i++) {
                        update[i] = header;
                    }
                    level = newLevel;
                }

                SkipListNode newNode = new SkipListNode(key, newLevel);

                for (int i = 0; i <= newLevel; i++) {
                    newNode.forward[i] = update[i].forward[i];
                    update[i].forward[i] = newNode;
                }
            }
        }

        /**
         * Delete key from SkipList. O(log n) average time.
         */
        public void delete(int key) {
            SkipListNode[] update = new SkipListNode[MAX_LEVEL + 1];
            SkipListNode current = header;

            for (int i = level; i >= 0; i--) {
                while (current.forward[i] != null && current.forward[i].key < key) {
                    current = current.forward[i];
                }
                update[i] = current;
            }

            current = current.forward[0];

            if (current != null && current.key == key) {
                for (int i = 0; i <= level; i++) {
                    if (update[i].forward[i] != current) {
                        break;
                    }
                    update[i].forward[i] = current.forward[i];
                }

                while (level > 0 && header.forward[level] == null) {
                    level--;
                }
            }
        }

        /**
         * Display SkipList structure.
         */
        public void display() {
            System.out.println("SkipList structure:");
            for (int level = this.level; level >= 0; level--) {
                SkipListNode current = header.forward[level];
                String levelStr = "Level " + level + ": ";
                while (current != null) {
                    levelStr += current.key + " -> ";
                    current = current.forward[level];
                }
                levelStr += "None";
                System.out.println(levelStr);
            }
        }
    }

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        // Create SkipList instance
        SkipListImpl skipList = new SkipListImpl();
        
        // Insert elements
        int[] elements = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
        for (int elem : elements) {
            skipList.insert(elem);
        }

        // Display structure
        skipList.display();
        
        // Search operations
        int[] searchKeys = {19, 15, 21};
        System.out.println("\nSearch results:");
        for (int key : searchKeys) {
            Integer result = skipList.search(key);
            System.out.println("Search for " + key + ": " + (result != null ? "Found" : "Not found"));
        }
        
        // Delete operation
        skipList.delete(17);
        System.out.println("\nAfter deleting 17:");
        skipList.display();
        
        long endTime = System.nanoTime();
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;
        
        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.printf("Execution time: %.4f ms%n", (endTime - startTime) / 1_000_000.0);
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("\nTime Complexity (Average):");
        System.out.println("  - Search: O(log n)");
        System.out.println("  - Insert: O(log n)");
        System.out.println("  - Delete: O(log n)");
        System.out.println("  - Space: O(n)");
    }
}