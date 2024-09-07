#include <iostream>
#include <vector>

class ArrayList {
private:
    std::vector<int> arr;  // Vector to store the elements

public:
    // Constructor to initialize the vector with a given capacity
    ArrayList(int cap = 10) {
        arr.reserve(cap);  // Reserve capacity to avoid frequent reallocations
    }

    // Function to add an element at the end
    void add(int element) {
        if (arr.size() == arr.capacity()) {
            std::cout << "Array is full, cannot add more elements!" << std::endl;
            return;
        }
        arr.push_back(element);
    }

    // Function to remove an element from a specific index
    void remove(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }
        arr.erase(arr.begin() + index);
    }

    // Function to get an element at a specific index
    int get(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Invalid index!" << std::endl;
            return -1;  // Return -1 for invalid index
        }
        return arr[index];
    }

    // Function to display all elements
    void display() {
        if (arr.empty()) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }
        std::cout << "List elements: ";
        for (int element : arr) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // Function to get the size of the list
    int getSize() {
        return arr.size();
    }
};

int main() {
    ArrayList myList(5);  // Create a list with an initial capacity of 5

    // Adding elements to the list
    myList.add(10);
    myList.add(20);
    myList.add(30);
    myList.add(40);
    myList.add(50);

    // Display the list
    myList.display();  // Output: List elements: 10 20 30 40 50

    // Removing an element at index 2
    myList.remove(2);

    // Display the list again
    myList.display();  // Output: List elements: 10 20 40 50

    // Get an element at index 1
    std::cout << "Element at index 1: " << myList.get(1) << std::endl;  // Output: 20

    // Trying to add another element (should succeed as vector can grow dynamically)
    myList.add(60);  
    myList.display();  // Output: List elements: 10 20 40 50 60

    return 0;
}

