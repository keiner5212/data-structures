package DoublyLinkedList;


/**
 * Demonstrates doubly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
public class DoublyLinkedList {
    /**
     * Doubly linked list implementation with basic operations.
     * Each node contains data and references to both previous and next nodes.
     */
    static class Node<T> {
        T data;
        Node<T> prev;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    static class DoublyLinkedListImpl<T> {
        private Node<T> head;
        private Node<T> tail;
        private int size;

        DoublyLinkedListImpl() {
            this.head = null;
            this.tail = null;
            this.size = 0;
        }

        /**
         * Check if list is empty. O(1) operation.
         */
        boolean isEmpty() {
            return head == null;
        }

        /**
         * Return number of elements in list. O(1) operation.
         */
        int getSize() {
            return size;
        }

        /**
         * Insert element at the beginning of the list. O(1) operation.
         */
        void insertAtBeginning(T data) {
            Node<T> newNode = new Node<>(data);
            if (isEmpty()) {
                head = tail = newNode;
            } else {
                newNode.next = head;
                head.prev = newNode;
                head = newNode;
            }
            size++;
        }

        /**
         * Insert element at the end of the list. O(1) operation.
         */
        void insertAtEnd(T data) {
            Node<T> newNode = new Node<>(data);
            if (isEmpty()) {
                head = tail = newNode;
            } else {
                newNode.prev = tail;
                tail.next = newNode;
                tail = newNode;
            }
            size++;
        }

        /**
         * Insert element at specified position. O(n) operation.
         */
        void insertAtPosition(T data, int position) {
            if (position < 0 || position > size) {
                throw new IllegalArgumentException("Invalid position");
            }

            if (position == 0) {
                insertAtBeginning(data);
                return;
            }

            if (position == size) {
                insertAtEnd(data);
                return;
            }

            Node<T> newNode = new Node<>(data);
            Node<T> current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current.next;
            }

            newNode.next = current.next;
            newNode.prev = current;
            current.next.prev = newNode;
            current.next = newNode;
            size++;
        }

        /**
         * Delete element from the beginning of the list. O(1) operation.
         */
        T deleteFromBeginning() {
            if (isEmpty()) {
                return null;
            }

            T deletedData = head.data;
            if (head == tail) {
                head = tail = null;
            } else {
                head = head.next;
                head.prev = null;
            }
            size--;
            return deletedData;
        }

        /**
         * Delete element from the end of the list. O(1) operation.
         */
        T deleteFromEnd() {
            if (isEmpty()) {
                return null;
            }

            T deletedData = tail.data;
            if (head == tail) {
                head = tail = null;
            } else {
                tail = tail.prev;
                tail.next = null;
            }
            size--;
            return deletedData;
        }

        /**
         * Delete first occurrence of value. O(n) operation.
         */
        boolean deleteByValue(T value) {
            if (isEmpty()) {
                return false;
            }

            Node<T> current = head;
            while (current != null) {
                if (current.data.equals(value)) {
                    if (current == head) {
                        deleteFromBeginning();
                    } else if (current == tail) {
                        deleteFromEnd();
                    } else {
                        current.prev.next = current.next;
                        current.next.prev = current.prev;
                        size--;
                    }
                    return true;
                }
                current = current.next;
            }
            return false;
        }

        /**
         * Search for value in the list. O(n) operation.
         */
        int search(T value) {
            Node<T> current = head;
            int position = 0;
            while (current != null) {
                if (current.data.equals(value)) {
                    return position;
                }
                current = current.next;
                position++;
            }
            return -1;
        }

        /**
         * Display all elements from head to tail.
         */
        void displayForward() {
            if (isEmpty()) {
                System.out.println("List is empty");
                return;
            }

            Node<T> current = head;
            StringBuilder sb = new StringBuilder();
            while (current != null) {
                sb.append(current.data.toString());
                if (current.next != null) {
                    sb.append(" -> ");
                }
                current = current.next;
            }
            System.out.println(sb.toString());
        }

        /**
         * Display all elements from tail to head.
         */
        void displayBackward() {
            if (isEmpty()) {
                System.out.println("List is empty");
                return;
            }

            Node<T> current = tail;
            StringBuilder sb = new StringBuilder();
            while (current != null) {
                sb.append(current.data.toString());
                if (current.prev != null) {
                    sb.append(" <- ");
                }
                current = current.prev;
            }
            System.out.println(sb.toString());
        }
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();
        long memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

        // Create doubly linked list instance
        DoublyLinkedListImpl<Integer> dll = new DoublyLinkedListImpl<>();

        // Insert elements
        dll.insertAtEnd(10);
        dll.insertAtEnd(20);
        dll.insertAtBeginning(5);
        dll.insertAtPosition(15, 2);

        System.out.println("List after insertions (forward):");
        dll.displayForward();

        System.out.println("\nList after insertions (backward):");
        dll.displayBackward();

        // Search operations
        Integer[] searchValues = {15, 25};
        System.out.println("\nSearch results:");
        for (Integer value : searchValues) {
            int position = dll.search(value);
            if (position != -1) {
                System.out.println("Value " + value + " found at position " + position);
            } else {
                System.out.println("Value " + value + " not found");
            }
        }

        // Delete operations
        dll.deleteByValue(20);
        System.out.println("\nList after deleting 20 (forward):");
        dll.displayForward();

        dll.deleteFromBeginning();
        System.out.println("\nList after deleting from beginning (forward):");
        dll.displayForward();

        dll.deleteFromEnd();
        System.out.println("\nList after deleting from end (forward):");
        dll.displayForward();

        long endTime = System.nanoTime();
        long memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;

        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.println("Execution time: " + ((endTime - startTime) / 1_000_000.0) + " ms");
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("Final list size: " + dll.getSize());
        System.out.println("\nTime Complexity:");
        System.out.println("  - Insert at beginning: O(1)");
        System.out.println("  - Insert at end: O(1)");
        System.out.println("  - Insert at position: O(n)");
        System.out.println("  - Delete from beginning: O(1)");
        System.out.println("  - Delete from end: O(1)");
        System.out.println("  - Delete by value: O(n)");
        System.out.println("  - Search: O(n)");
        System.out.println("  - Get size: O(1)");
    }
}