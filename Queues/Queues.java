package Queues;

import java.util.LinkedList;
import java.util.Queue;

/**
 * This program demonstrates basic operations with a queue using the Queue interface and LinkedList.
 */
public class Queues {

    public static void main(String[] args) {
        // Declaration of a queue of integers
        Queue<Integer> myQueue = new LinkedList<>();

        // Enqueuing values into the queue
        myQueue.offer(10);
        myQueue.offer(20);
        myQueue.offer(30);
        myQueue.offer(40);
        myQueue.offer(50);

        // Accessing the elements of the queue and printing to the console
        System.out.println("Elements in the Queue:");
        while (!myQueue.isEmpty()) {
            System.out.println("Dequeued Element: " + myQueue.poll());
        }
    }
}
