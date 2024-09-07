#include <iostream>
using namespace std;
class ArrayList {
private:
    int* arr;           // Pointer to the array
    int capacity;       // Total capacity of the array
    int size;           // Current number of elements

public:
    // Constructor to initialize the array with a given capacity
    ArrayList(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];  // Dynamically allocate memory for the array
    }

    // Destructor to release allocated memory
    ~ArrayList() {
        delete[] arr;
    }

    // Function to add an element at the end
    void add(int element) {
        if (size == capacity) {
            std::cout << "Array is full, cannot add more elements!" << std::endl;
            return;
        }
        arr[size] = element;
        size++;
    }

    // Function to remove an element from a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << std::endl;
            return;
        }

        // Shift elements to the left to fill the gap
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;  // Reduce the size of the array
    }

    // Function to get an element at a specific index
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << std::endl;
            return -1;  // Return -1 for invalid index
        }
        return arr[index];
    }

    // Function to display all elements
    void display() {
        if (size == 0) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }
        std::cout << "List elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Function to get the size of the list
    int getSize() {
        return size;
    }
 int getCapacity() {
        return capcity;
    }
};

int main() {
    ArrayList myList(5);  // Create a list with a capacity of 5

    // Adding elements to the list
    myList.add(10);
    myList.add(20);
    myList.add(30);
    myList.add(40);
    myList.add(50);

    // Display the list
    myList.display();  // Output: List elements: [10 20 30 40 50]

    // Removing an element at index 2 [ 10 20 40 50]
    myList.remove(2);

    // Display the list again
    myList.display();  // Output: List elements: 10 20 40 50

    // Get an element at index 1
    std::cout << "Element at index 1: " << myList.get(1) << std::endl;  // Output: 20

    // Trying to add another element (should fail as capacity is reached)
    myList.add(60);  // Output: Array is full, cannot add more elements!

    return 0;
}

