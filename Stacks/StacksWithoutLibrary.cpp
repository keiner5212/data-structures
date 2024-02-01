#include <iostream>
using namespace std;

// Define a simple stack structure
struct Stack {
    int capacity;
    int top;
    int* array;
};

// Function to create a stack with a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = new Stack;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[capacity];
    return stack;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        cout << "Stack Overflow\n";
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack->array[stack->top--];
}

/**
 * @brief This program demonstrates basic operations with a stack.
 * 
 * The program pushes values onto a stack, pops values from the stack, 
 * and prints the elements of the stack to the console.
 * 
 * @return 0 indicating successful execution.
 */
int main() {
    // Create a stack with a capacity of 5
    struct Stack* myStack = createStack(5);

    // Pushing values onto the stack
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);

    // Accessing the elements of the stack and printing to the console
    cout << "Elements in the Stack:" << endl;
    while (!isEmpty(myStack)) {
        cout << "Element: " << pop(myStack) << endl;
    }

    // Clean up and free the memory
    delete[] myStack->array;
    delete myStack;

    return 0;
}
