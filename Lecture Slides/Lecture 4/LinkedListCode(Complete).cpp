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
    void insertBefore(int value, int newValue);
    void deleteFromStart();
    void deleteFromEnd();
    void deleteAfter(int value);
    void deleteBefore(int value);
};

// Insert at the end of the linked list
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
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

// Display the linked list
void LinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at the start of the linked list
void LinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert after a specific value
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

// Insert before a specific value
void LinkedList::insertBefore(int value, int newValue) {
    Node* newNode = new Node(newValue);
    // If the list is empty
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    // If the head node is the one containing the value
    if (head->data == value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    // Traverse to find the node before the specific value
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Node with value " << value << " not found." << endl;
    }
}

// Delete from the start of the linked list
void LinkedList::deleteFromStart() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from the end of the linked list
void LinkedList::deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Delete after a specific value
void LinkedList::deleteAfter(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    } else {
        cout << "Node with value " << value << " not found or no node to delete after it." << endl;
    }
}

// Delete before a specific value
void LinkedList::deleteBefore(int value) {
    if (head == NULL || head->next == NULL) {
        cout << "List is empty or has only one node." << endl;
        return;
    }
    if (head->data == value) {
        cout << "No node present before the head." << endl;
        return;
    }
    // If the node before the specific value is the head
    if (head->next->data == value) {
        deleteFromStart();
        return;
    }
    // Traverse to find the node before the node containing the specific value
    Node* temp = head;
    while (temp->next->next != NULL && temp->next->next->data != value) {
        temp = temp->next;
    }
    if (temp->next->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
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

    // Inserting node before a specific value
    list.insertBefore(3, 7);

    // Displaying the linked list
    cout << "Linked List: ";
    list.display();

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

