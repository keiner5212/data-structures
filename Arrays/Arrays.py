def main():
    """
    This program demonstrates the declaration, assignment, and access of elements in an integer array.
    It declares an array of integers with 5 elements, assigns values to each element,
    and then prints the elements of the array to the console."""
    # Declaration of an array of integers with 5 elements
    mi_array = [10, 20, 30, 40, 50]

    # Accessing the elements of the array and printing to the console
    for i, value in enumerate(mi_array):
        print(f"Element {i}: {value}")

main()
