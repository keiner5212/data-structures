package Stacks;

import java.util.ArrayList;
import java.util.List;

// Stack class
class Stack {
    private List<Integer> items;

    // Constructor
    public Stack() {
        this.items = new ArrayList<>();
    }

    // Push method adds an element to the stack
    public void push(int item) {
        items.add(item);
    }

    // Pop method removes and returns the top element from the stack
    public int pop() {
        if (isEmpty()) {
            return -1; // Indicates empty stack
        }
        int item = items.get(items.size() - 1);
        items.remove(items.size() - 1);
        return item;
    }

    // IsEmpty method checks if the stack is empty
    public boolean isEmpty() {
        return items.isEmpty();
    }

}

public class StacksWithoutLibrary {
    public static void main(String[] args) {
        // Create an instance of the stack
        Stack myStack = new Stack();

        // Add elements to the stack
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40);
        myStack.push(50);

        // Pop elements from the stack and display them
        System.out.println("\nPop elements from the Stack:");
        while (!myStack.isEmpty()) {
            System.out.printf("Popped Element: %d\n", myStack.pop());
        }
    }
}
