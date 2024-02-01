package Queues;

public class QueuesWithoutLibrary {
    /**
     * This program demonstrates basic operations with a queue without using any
     * library.
     */
    public class CustomQueueExample {

        // Node class for the elements in the queue
        private static class Node {
            int data;
            Node next;

            Node(int value) {
                data = value;
                next = null;
            }
        }

        // Queue class
        private static class CustomQueue {
            private Node front;
            private Node rear;

            // Constructor
            public CustomQueue() {
                front = rear = null;
            }

            // Enqueue method to add elements to the queue
            public void enqueue(int value) {
                Node newNode = new Node(value);
                if (isEmpty()) {
                    front = rear = newNode;
                } else {
                    rear.next = newNode;
                    rear = newNode;
                }
            }

            // Dequeue method to remove and return the front element from the queue
            public int dequeue() {
                if (isEmpty()) {
                    System.err.println("Error: Attempting to dequeue from an empty queue.");
                    return -1; // Indicates empty queue
                }

                int value = front.data;
                front = front.next;

                if (front == null) {
                    rear = null; // Reset rear when the last element is dequeued
                }

                return value;
            }

            // IsEmpty method to check if the queue is empty
            public boolean isEmpty() {
                return front == null;
            }
        }

        public static void main(String[] args) {
            // Create an instance of the custom queue
            CustomQueue myQueue = new CustomQueue();

            // Enqueue elements to the queue
            myQueue.enqueue(10);
            myQueue.enqueue(20);
            myQueue.enqueue(30);
            myQueue.enqueue(40);
            myQueue.enqueue(50);

            // Access and print the elements of the queue
            System.out.println("Elements in the Queue:");
            while (!myQueue.isEmpty()) {
                System.out.println("Dequeued Element: " + myQueue.dequeue());
            }
        }
    }

}
