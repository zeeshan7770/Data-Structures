#include <iostream>
using namespace std;

// Structure definition
struct Address {
    string city;
    string state;
    int zip;
};

// Nested structure
struct Person {
    string name;
    int age;
    Address address;  // Nested structure

    // Member function to display person details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Address: " << address.city << ", " << address.state << ", " << address.zip << endl;
    }
};

// Function to pass structure by value
void modifyPerson(Person p) {
    p.age = 35;  // Changes will not affect the original structure
    cout << "\nInside modifyPerson (by value), updated age: " << p.age << endl;
}

// Function to pass structure by reference
void modifyPersonByReference(Person& p) {
    p.age = 40;  // Changes will reflect on the original structure
    cout << "\nInside modifyPersonByReference (by reference), updated age: " << p.age << endl;
}

int main() {
    // Initializing structure
    Person person1 = {"Alice", 30, {"New York", "NY", 10001}};

    // Displaying structure data using member function
    cout << "Person Details:" << endl;
    person1.display();

    // Passing structure to function by value
    modifyPerson(person1);
    cout << "\nAfter modifyPerson (by value), original age: " << person1.age << endl;

    // Passing structure to function by reference
    modifyPersonByReference(person1);
    cout << "After modifyPersonByReference (by reference), original age: " << person1.age << endl;

    // Array of structures
    cout << "\nArray of Structures:" << endl;
    Person people[2] = {
        {"Bob", 25, {"Los Angeles", "CA", 90001}},
        {"Charlie", 28, {"Chicago", "IL", 60601}}
    };

    for (int i = 0; i < 2; i++) {
        people[i].display();
    }

    // Pointer to structure
    cout << "\nPointer to Structure:" << endl;
    Person* ptr = &person1;
    ptr->age = 45;  // Access structure members using pointer
    ptr->display();

    return 0;
}

