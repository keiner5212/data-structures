/**
 * Singly linked list implementation with basic operations.
 * Each node contains data and a pointer to the next node.
 */
#include <iostream>
#include <chrono>
#include <memory>

template <typename T>
class Node {
public:
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    size_t size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    /**
     * Check if list is empty. O(1) operation.
     */
    bool isEmpty() const {
        return head == nullptr;
    }

    /**
     * Return number of elements in list. O(1) operation.
     */
    size_t getSize() const {
        return size;
    }

    /**
     * Insert element at the beginning of the list. O(1) operation.
     */
    void insertAtBeginning(T data) {
        auto newNode = std::make_unique<Node<T>>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    /**
     * Insert element at the end of the list. O(n) operation.
     */
    void insertAtEnd(T data) {
        auto newNode = std::make_unique<Node<T>>(data);
        if (isEmpty()) {
            head = std::move(newNode);
        } else {
            Node<T>* current = head.get();
            while (current->next) {
                current = current->next.get();
            }
            current->next = std::move(newNode);
        }
        size++;
    }

    /**
     * Insert element at specified position. O(n) operation.
     */
    void insertAtPosition(T data, size_t position) {
        if (position > size) {
            throw std::out_of_range("Invalid position");
        }

        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        auto newNode = std::make_unique<Node<T>>(data);
        Node<T>* current = head.get();
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next.get();
        }

        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        size++;
    }

    /**
     * Delete element from the beginning of the list. O(1) operation.
     */
    T deleteFromBeginning() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }

        T deletedData = head->data;
        head = std::move(head->next);
        size--;
        return deletedData;
    }

    /**
     * Delete element from the end of the list. O(n) operation.
     */
    T deleteFromEnd() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }

        if (!head->next) {
            T deletedData = head->data;
            head = nullptr;
            size--;
            return deletedData;
        }

        Node<T>* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }

        T deletedData = current->next->data;
        current->next = nullptr;
        size--;
        return deletedData;
    }

    /**
     * Delete first occurrence of value. O(n) operation.
     */
    bool deleteByValue(T value) {
        if (isEmpty()) {
            return false;
        }

        if (head->data == value) {
            head = std::move(head->next);
            size--;
            return true;
        }

        Node<T>* current = head.get();
        while (current->next && current->next->data != value) {
            current = current->next.get();
        }

        if (current->next) {
            current->next = std::move(current->next->next);
            size--;
            return true;
        }

        return false;
    }

    /**
     * Search for value in the list. O(n) operation.
     */
    int search(T value) const {
        Node<T>* current = head.get();
        int position = 0;
        while (current) {
            if (current->data == value) {
                return position;
            }
            current = current->next.get();
            position++;
        }
        return -1;
    }

    /**
     * Display all elements in the list.
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node<T>* current = head.get();
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << " -> ";
            }
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};

/**
 * Demonstrates singly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    // Create linked list instance
    SinglyLinkedList<int> sll;

    // Insert elements
    sll.insertAtEnd(10);
    sll.insertAtEnd(20);
    sll.insertAtBeginning(5);
    sll.insertAtPosition(15, 2);

    std::cout << "List after insertions:" << std::endl;
    sll.display();

    // Search operations
    int searchValues[] = {15, 25};
    std::cout << "\nSearch results:" << std::endl;
    for (size_t i = 0; i < sizeof(searchValues) / sizeof(searchValues[0]); i++) {
        int value = searchValues[i];
        int position = sll.search(value);
        if (position != -1) {
            std::cout << "Value " << value << " found at position " << position << std::endl;
        } else {
            std::cout << "Value " << value << " not found" << std::endl;
        }
    }

    // Delete operations
    sll.deleteByValue(20);
    std::cout << "\nList after deleting 20:" << std::endl;
    sll.display();

    sll.deleteFromBeginning();
    std::cout << "\nList after deleting from beginning:" << std::endl;
    sll.display();

    sll.deleteFromEnd();
    std::cout << "\nList after deleting from end:" << std::endl;
    sll.display();

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: negligible (managed by smart pointers)" << std::endl;
    std::cout << "Final list size: " << sll.getSize() << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Insert at beginning: O(1)" << std::endl;
    std::cout << "  - Insert at end: O(n)" << std::endl;
    std::cout << "  - Insert at position: O(n)" << std::endl;
    std::cout << "  - Delete from beginning: O(1)" << std::endl;
    std::cout << "  - Delete from end: O(n)" << std::endl;
    std::cout << "  - Delete by value: O(n)" << std::endl;
    std::cout << "  - Search: O(n)" << std::endl;
    std::cout << "  - Get size: O(1)" << std::endl;

    return 0;
}