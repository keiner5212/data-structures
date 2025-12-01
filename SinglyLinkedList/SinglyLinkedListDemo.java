/**
 * Singly linked list implementation with basic operations.
 * Each node contains data and a reference to the next node.
 */
class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList<T> {
    private Node<T> head;
    private int size;

    SinglyLinkedList() {
        this.head = null;
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
        newNode.next = head;
        head = newNode;
        size++;
    }

    /**
     * Insert element at the end of the list. O(n) operation.
     */
    void insertAtEnd(T data) {
        Node<T> newNode = new Node<>(data);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node<T> current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
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

        Node<T> newNode = new Node<>(data);
        Node<T> current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current.next;
        }

        newNode.next = current.next;
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
        head = head.next;
        size--;
        return deletedData;
    }

    /**
     * Delete element from the end of the list. O(n) operation.
     */
    T deleteFromEnd() {
        if (isEmpty()) {
            return null;
        }

        if (head.next == null) {
            T deletedData = head.data;
            head = null;
            size--;
            return deletedData;
        }

        Node<T> current = head;
        while (current.next.next != null) {
            current = current.next;
        }

        T deletedData = current.next.data;
        current.next = null;
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

        if (head.data.equals(value)) {
            head = head.next;
            size--;
            return true;
        }

        Node<T> current = head;
        while (current.next != null && !current.next.data.equals(value)) {
            current = current.next;
        }

        if (current.next != null) {
            current.next = current.next.next;
            size--;
            return true;
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
     * Display all elements in the list.
     */
    void display() {
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
}

/**
 * Demonstrates singly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
public class SinglyLinkedListDemo {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        long memoryBefore = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

        // Create linked list instance
        SinglyLinkedList<Integer> sll = new SinglyLinkedList<>();

        // Insert elements
        sll.insertAtEnd(10);
        sll.insertAtEnd(20);
        sll.insertAtBeginning(5);
        sll.insertAtPosition(15, 2);

        System.out.println("List after insertions:");
        sll.display();

        // Search operations
        Integer[] searchValues = {15, 25};
        System.out.println("\nSearch results:");
        for (Integer value : searchValues) {
            int position = sll.search(value);
            if (position != -1) {
                System.out.println("Value " + value + " found at position " + position);
            } else {
                System.out.println("Value " + value + " not found");
            }
        }

        // Delete operations
        sll.deleteByValue(20);
        System.out.println("\nList after deleting 20:");
        sll.display();

        sll.deleteFromBeginning();
        System.out.println("\nList after deleting from beginning:");
        sll.display();

        sll.deleteFromEnd();
        System.out.println("\nList after deleting from end:");
        sll.display();

        long endTime = System.nanoTime();
        long memoryAfter = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        long memoryUsed = memoryAfter - memoryBefore;

        // Performance statistics
        System.out.println("\n--- Performance Statistics ---");
        System.out.println("Execution time: " + ((endTime - startTime) / 1_000_000.0) + " ms");
        System.out.println("Memory usage: " + (memoryUsed > 0 ? memoryUsed : "negligible") + " bytes");
        System.out.println("Final list size: " + sll.getSize());
        System.out.println("\nTime Complexity:");
        System.out.println("  - Insert at beginning: O(1)");
        System.out.println("  - Insert at end: O(n)");
        System.out.println("  - Insert at position: O(n)");
        System.out.println("  - Delete from beginning: O(1)");
        System.out.println("  - Delete from end: O(n)");
        System.out.println("  - Delete by value: O(n)");
        System.out.println("  - Search: O(n)");
        System.out.println("  - Get size: O(1)");
    }
}