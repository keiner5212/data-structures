#include <iostream>
using namespace std;

/**
 * @brief This program demonstrates the declaration, assignment, and access of elements in an integer array.
 * 
 * The program declares an array of integers with 5 elements, assigns values to each element, 
 * and then prints the elements of the array to the console.
 * 
 * @return 0 indicating successful execution.
 */
int main() {
    // Declaration of an array of integers with 5 elements
    int miArray[5];

    // Assignment of values to the elements of the array
    miArray[0] = 10;
    miArray[1] = 20;
    miArray[2] = 30;
    miArray[3] = 40;
    miArray[4] = 50;

    // same as:
    // int miArray[5] = {10, 20, 30, 40, 50};

    // Accessing the elements of the array and printing to the console
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << miArray[i] << endl;
    }

    return 0;
}
