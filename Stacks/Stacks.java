package Stacks;

import java.util.ArrayDeque;
import java.util.Deque;

public class Stacks {
    public static void main(String[] args) {
        // Crear una instancia de la pila utilizando ArrayDeque
        Deque<Integer> myStack = new ArrayDeque<>();

        // Agregar elementos a la pila
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40);
        myStack.push(50);

        // Pop elementos de la pila y mostrarlos
        System.out.println("\nPop elementos de la Pila:");
        while (!myStack.isEmpty()) {
            System.out.printf("Elemento Pop: %d\n", myStack.pop());
        }
    }
}
