#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief This program demonstrates basic operations with a stack.
 * 
 * The program pushes values onto a stack, pops values from the stack, 
 * and prints the elements of the stack to the console.
 * 
 * @return 0 indicating successful execution.
 */
int main() {
    // Declaration of a stack of integers
    stack<int> myStack;

    // Pushing values onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    // Accessing the elements of the stack and printing to the console
    cout << "Elements in the Stack:" << endl;
    while (!myStack.empty()) {
        cout << "Element: " << myStack.top() << endl;
        myStack.pop();
    }

    return 0;
}
