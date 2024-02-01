class Stack:
    def __init__(self):
        self.items = []

    # Push method to add elements to the stack
    def push(self, item):
        self.items.append(item)

    # Pop method to remove and return the top element from the stack
    def pop(self):
        if self.is_empty():
            return -1  # Indicates empty stack
        return self.items.pop()

    # IsEmpty method to check if the stack is empty
    def is_empty(self):
        return len(self.items) == 0

# Create an instance of the stack
my_stack = Stack()

# Add elements to the stack
my_stack.push(10)
my_stack.push(20)
my_stack.push(30)
my_stack.push(40)
my_stack.push(50)

# Access and print the elements of the stack
print("Elements in the Stack:")
while not my_stack.is_empty():
    print(f"Popped Element: {my_stack.pop()}")

# no poo way:
"""
my_stack = []

my_stack.append(10)
my_stack.append(20)
my_stack.append(30)

popped_element = my_stack.pop()

print("Popped Element:", popped_element)
print("Elements in the Stack:", my_stack)
"""