#include <iostream>

// Node structure for the elements in the queue
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free allocated memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Enqueue method to add elements to the queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue method to remove and return the front element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Error: Attempting to dequeue from an empty queue." << std::endl;
            return -1; // Indicates empty queue
        }

        int value = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr; // Reset rear when the last element is dequeued
        }

        return value;
    }

    // IsEmpty method to check if the queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }
};

// Main function
int main()
{
    // Create an instance of the queue
    Queue myQueue;

    // Enqueue elements to the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Access and print the elements of the queue
    std::cout << "Elements in the Queue:" << std::endl;
    while (!myQueue.isEmpty())
    {
        std::cout << "Dequeued Element: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}
