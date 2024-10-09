#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) { // Constructor to initialize node with value
        data = value;
        next = NULL;
    }
};

class DynamicStack {
private:
    Node* top; // Pointer to the top node

public:
    DynamicStack() { // Constructor initializes top as null (empty stack)
        top = null;
    }

    bool isEmpty() {
        return top == null; // Stack is empty when top is null
    }

    void push(int value) {
        Node* newNode = new Node(value); // Allocate new node
        newNode->next = top; // Link new node to the previous top
        top = newNode;       // Set new node as the top
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!" << std::endl;
            return;
        }
        Node* temp = top;    // Save the current top
        top = top->next;     // Move top pointer to the next node
        delete temp;         // Delete the old top node
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data; // Return the top node's data
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        Node* temp = top;
        std::cout << "Stack elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Output: 30 20 10

    std::cout << "Top element: " << s.peek() << std::endl; // Output: 30

    s.pop();
    s.display(); // Output: 20 10

    return 0;
}

