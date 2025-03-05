#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string details;
    int priority;
    Node* next;

    Node(int id, string details, int priority) {
        this->id = id;
        this->details = details;
        this->priority = priority;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void removeFromStart() {
        if (head == NULL) {
            cout << "Task list is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Removed Task ID: " << temp->id << " (Priority: " << temp->priority << ")\n";
        delete temp;
    }

    void removeFromEnd() {
        if (head == NULL) {
            cout << "Task list is empty\n";
            return;
        }
        if (head == tail) {
            cout << "Removed Task ID: " << head->id << " (Priority: " << head->priority << ")\n";
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        cout << "Removed Task ID: " << tail->id << " (Priority: " << tail->priority << ")\n";
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void removeFromMiddle(int id) {
        if (head == NULL) {
            cout << "Task list is empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Task with ID " << id << " not found!\n";
            return;
        }

        if (temp == head) {
            removeFromStart();
            return;
        }

        if (temp == tail) {
            removeFromEnd();
            return;
        }

        prev->next = temp->next;
        cout << "Removed Task ID: " << temp->id << " (Priority: " << temp->priority << ")\n";
        delete temp;
    }

    void addByPriority(int id, string details, int priority) {
        Node* newTask = new Node(id, details, priority);

        if (head == NULL) {
            head = tail = newTask;
            return;
        }

        if (priority < head->priority) {
            newTask->next = head;
            head = newTask;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->priority <= priority) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = newTask;
        newTask->next = temp;

        if (temp == NULL) {
            tail = newTask;
        }
    }

    void removeTopPriority() {
        if (head == NULL) {
            cout << "No tasks available to remove.\n";
            return;
        }
        removeFromStart();
    }

    void displayTasks() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "No tasks available.\n";
            return;
        }
        while (temp != NULL) {
            cout << "Task ID: " << temp->id << "  Details: "
                 << temp->details << "  Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

int main() {
    List taskList;
    int i = 0;
    while (i != 1) {
        cout << " Task Management System \n";
        cout << "1) Add Task\n";
        cout << "2) View Tasks\n";
        cout << "3) Remove Highest Priority Task\n";
        cout << "4) Remove Task by ID\n";
        cout << "5) Exit\n";

        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, priority;
            string details;

            cout << "Enter Task ID: ";
            cin >> id;

            cout << "Enter Task Details: ";
            cin.ignore(); // Clear input buffer
            getline(cin, details);

            cout << "Enter Priority Level: ";
            cin >> priority;

            taskList.addByPriority(id, details, priority);
        } else if (choice == 2) {
            cout << " View Tasks \n";
            taskList.displayTasks();
        } else if (choice == 3) {
            taskList.removeTopPriority();
        } else if (choice == 4) {
            int id;
            cout << "Enter Task ID to Remove: ";
            cin >> id;
            taskList.removeFromMiddle(id);
        } else if (choice == 5) {
            i = 1;
            cout << "Exiting the program\n";
            break;
        } else {
            cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}
