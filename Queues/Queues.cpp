#include <iostream>
#include <queue>

/**
 * @brief This program demonstrates basic operations with a queue.
 * 
 * The program enqueues values into a queue, dequeues values from the queue, 
 * and prints the elements of the queue to the console.
 * 
 * @return 0 indicating successful execution.
 */
int main() {
    // Declaration of a queue of integers
    std::queue<int> myQueue;

    // Enqueuing values into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    // Accessing the elements of the queue and printing to the console
    std::cout << "Elements in the Queue:" << std::endl;
    while (!myQueue.empty()) {
        std::cout << "Dequeued Element: " << myQueue.front() << std::endl;
        myQueue.pop();
    }

    return 0;
}
