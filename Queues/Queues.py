class Queue:
    def __init__(self):
        self.items = []

    # Enqueue method to add elements to the queue
    def enqueue(self, item):
        self.items.append(item)

    # Dequeue method to remove and return the front element from the queue
    def dequeue(self):
        if self.is_empty():
            return -1  # Indicates empty queue
        return self.items.pop(0)

    # IsEmpty method to check if the queue is empty
    def is_empty(self):
        return len(self.items) == 0


# Create an instance of the queue
my_queue = Queue()

# Enqueue elements to the queue
my_queue.enqueue(10)
my_queue.enqueue(20)
my_queue.enqueue(30)
my_queue.enqueue(40)
my_queue.enqueue(50)

# Access and print the elements of the queue
print("Elements in the Queue:")
while not my_queue.is_empty():
    print(f"Dequeued Element: {my_queue.dequeue()}")
