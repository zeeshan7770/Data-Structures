#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insertAtEnd(int value);
    void display();
    void insertAtStart(int value);
    void insertAfter(int value, int newValue);
};
/*
list empty: 
*/
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    /*empty list*/
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAfter(int value, int newValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Node with value " << value << " not found." << endl;
    }
}

int main() {
    LinkedList list;

    // Inserting nodes at the end
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    // Inserting node at the start
    list.insertAtStart(0);

    // Inserting node after a specific value
    list.insertAfter(2, 5);

    // Displaying the linked list
    cout << "Linked List: ";
    list.display();

    return 0;
}

