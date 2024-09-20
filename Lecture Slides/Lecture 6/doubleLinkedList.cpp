#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;  // Tail node to optimize end operations

    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtEnd(int value);
    void display();
    void displayReverse();
    void insertAtStart(int value);
    void insertAfter(int value, int newValue);
    void insertBefore(int value, int newValue);
    void deleteFromStart();
    void deleteFromEnd();
    void deleteAfter(int value);
    void deleteBefore(int value);
};

// Insert at the end of the doubly linked list
void DoublyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = tail = newNode;  // Both head and tail point to the new node if list is empty
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;  // Update the tail to the new node
    }
}

// Display the doubly linked list (forward traversal)
void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display the doubly linked list in reverse order (backward traversal)
void DoublyLinkedList::displayReverse() {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// Insert at the start of the doubly linked list
void DoublyLinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = tail = newNode;  // Both head and tail point to the new node if list is empty
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;  // Update the head to the new node
    }
}

// Insert after a specific value
void DoublyLinkedList::insertAfter(int value, int newValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;  // Update the tail if inserted at the end
        }
        temp->next = newNode;
    } else {
        cout << "Node with value " << value << " not found." << endl;
    }
}

// Insert before a specific value
void DoublyLinkedList::insertBefore(int value, int newValue) {
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == value) {
        insertAtStart(newValue);  // If inserting before the head, just insert at the start
        return;
    }
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = new Node(newValue);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    } else {
        cout << "Node with value " << value << " not found." << endl;
    }
}

// Delete from the start of the doubly linked list
void DoublyLinkedList::deleteFromStart() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;  // If the list has only one node
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

// Delete from the end of the doubly linked list
void DoublyLinkedList::deleteFromEnd() {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;  // If the list has only one node
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

// Delete after a specific value
void DoublyLinkedList::deleteAfter(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = temp;
        } else {
            tail = temp;  // Update tail if deleting the last node
        }
        delete nodeToDelete;
    } else {
        cout << "Node with value " << value << " not found or no node to delete after it." << endl;
    }
}

// Delete before a specific value
void DoublyLinkedList::deleteBefore(int value) {
    Node* temp = head;
    if (head == NULL || head->next == NULL) {
        cout << "List is empty or has only one node." << endl;
        return;
    }
    if (head->data == value) {
        cout << "No node present before the head." << endl;
        return;
    }
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL && temp->prev != NULL) {
        Node* nodeToDelete = temp->prev;
        if (nodeToDelete->prev != NULL) {
            nodeToDelete->prev->next = temp;
        } else {
            head = temp;  // Update head if deleting the first node
        }
        temp->prev = nodeToDelete->prev;
        delete nodeToDelete;
    } else {
        cout << "Node with value " << value << " not found or no node to delete before it." << endl;
    }
}

int main() {
    DoublyLinkedList list;

    // Inserting nodes at the end
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    // Inserting node at the start
    list.insertAtStart(0);

    // Inserting node after a specific value
    list.insertAfter(2, 5);

    // Inserting node before a specific value
    list.insertBefore(3, 7);

    // Displaying the linked list
    cout << "Doubly Linked List (forward): ";
    list.display();

    // Displaying the linked list in reverse
    cout << "Doubly Linked List (reverse): ";
    list.displayReverse();

    // Deleting from start
    list.deleteFromStart();
    cout << "After deleting from start: ";
    list.display();

    // Deleting from end
    list.deleteFromEnd();
    cout << "After deleting from end: ";
    list.display();

    // Deleting after a specific value
    list.deleteAfter(1);
    cout << "After deleting after value 1: ";
    list.display();

    // Deleting before a specific value
    list.deleteBefore(5);
    cout << "After deleting before value 5: ";
    list.display();

    return 0;
}

