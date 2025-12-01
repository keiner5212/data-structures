/**
 * Doubly linked list implementation with basic operations.
 * Each node contains data and pointers to both previous and next nodes.
 */
#include <iostream>
#include <chrono>
#include <memory>

template <typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> prev;
    std::shared_ptr<Node<T>> next;

    Node(T data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

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
        auto newNode = std::make_shared<Node<T>>(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    /**
     * Insert element at the end of the list. O(1) operation.
     */
    void insertAtEnd(T data) {
        auto newNode = std::make_shared<Node<T>>(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
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

        if (position == size) {
            insertAtEnd(data);
            return;
        }

        auto newNode = std::make_shared<Node<T>>(data);
        auto current = head;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
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
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        size--;
        return deletedData;
    }

    /**
     * Delete element from the end of the list. O(1) operation.
     */
    T deleteFromEnd() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }

        T deletedData = tail->data;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
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

        auto current = head;
        while (current) {
            if (current->data == value) {
                if (current == head) {
                    deleteFromBeginning();
                } else if (current == tail) {
                    deleteFromEnd();
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    size--;
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }

    /**
     * Search for value in the list. O(n) operation.
     */
    int search(T value) const {
        auto current = head;
        int position = 0;
        while (current) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    /**
     * Display all elements from head to tail.
     */
    void displayForward() const {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        auto current = head;
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    /**
     * Display all elements from tail to head.
     */
    void displayBackward() const {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        auto current = tail;
        while (current) {
            std::cout << current->data;
            if (current->prev) {
                std::cout << " <- ";
            }
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

/**
 * Demonstrates doubly linked list operations.
 * Performs insertions, deletions, and searches on the list.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    // Create doubly linked list instance
    DoublyLinkedList<int> dll;

    // Insert elements
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(15, 2);

    std::cout << "List after insertions (forward):" << std::endl;
    dll.displayForward();

    std::cout << "\nList after insertions (backward):" << std::endl;
    dll.displayBackward();

    // Search operations
    int searchValues[] = {15, 25};
    std::cout << "\nSearch results:" << std::endl;
    for (size_t i = 0; i < sizeof(searchValues) / sizeof(searchValues[0]); i++) {
        int value = searchValues[i];
        int position = dll.search(value);
        if (position != -1) {
            std::cout << "Value " << value << " found at position " << position << std::endl;
        } else {
            std::cout << "Value " << value << " not found" << std::endl;
        }
    }

    // Delete operations
    dll.deleteByValue(20);
    std::cout << "\nList after deleting 20 (forward):" << std::endl;
    dll.displayForward();

    dll.deleteFromBeginning();
    std::cout << "\nList after deleting from beginning (forward):" << std::endl;
    dll.displayForward();

    dll.deleteFromEnd();
    std::cout << "\nList after deleting from end (forward):" << std::endl;
    dll.displayForward();

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: negligible (managed by smart pointers)" << std::endl;
    std::cout << "Final list size: " << dll.getSize() << std::endl;
    std::cout << "\nTime Complexity:" << std::endl;
    std::cout << "  - Insert at beginning: O(1)" << std::endl;
    std::cout << "  - Insert at end: O(1)" << std::endl;
    std::cout << "  - Insert at position: O(n)" << std::endl;
    std::cout << "  - Delete from beginning: O(1)" << std::endl;
    std::cout << "  - Delete from end: O(1)" << std::endl;
    std::cout << "  - Delete by value: O(n)" << std::endl;
    std::cout << "  - Search: O(n)" << std::endl;
    std::cout << "  - Get size: O(1)" << std::endl;

    return 0;
}