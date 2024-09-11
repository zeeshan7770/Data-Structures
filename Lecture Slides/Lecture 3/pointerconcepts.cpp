#include <iostream>
using namespace std;

// Function to demonstrate pointer to a function
void printValue(int* p) {
    cout << "Value pointed by p: " << *p << endl;
}

int main() {
    // Basic pointer declaration and usage
    int num = 10;
    int* ptr = &num;  // Pointer stores the address of 'num'

    cout << "Address of num: " << &num << endl;
    cout << "Value stored in ptr (address of num): " << ptr << endl;
    cout << "Value pointed by ptr (*ptr): " << *ptr << endl;

    // Pointer arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptrArr = arr;  // Points to the first element of the array

    cout << "\nPointer Arithmetic with Arrays:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *ptrArr << " at address " << ptrArr << endl;
        ptrArr++;  // Moves to the next element (increments by size of int)
    }

    // Pointers and arrays
    int* arrayPtr = arr;  // Array name is a pointer to its first element
    cout << "\nUsing Pointers with Arrays:" << endl;
    cout << "First element: " << *arrayPtr << endl;  // Same as arr[0]
    cout << "Second element: " << *(arrayPtr + 1) << endl;  // Same as arr[1]

    // Pointer to a function
    cout << "\nPointer to a Function:" << endl;
    int value = 100;
    printValue(&value);  // Passing the address of 'value' to function

    // Pointers to pointers
    int* p1 = &num;
    int** p2 = &p1;  // Pointer to pointer

    cout << "\nPointers to Pointers:" << endl;
    cout << "Address of p1: " << &p1 << endl;
    cout << "Value stored in p1 (address of num): " << p1 << endl;
    cout << "Value pointed by p1 (num): " << *p1 << endl;
    cout << "Address of p2: " << &p2 << endl;
    cout << "Value stored in p2 (address of p1): " << p2 << endl;
    cout << "Value pointed by p2 (*p2, i.e., value stored in p1): " << *p2 << endl;
    cout << "Value pointed by *p2 (i.e., value of num): " << **p2 << endl;

    return 0;
}

