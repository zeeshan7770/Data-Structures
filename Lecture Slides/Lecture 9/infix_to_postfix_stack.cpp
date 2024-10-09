#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to perform the conversion from infix to postfix
string infixToPostfix(string infix) {
    stack<char> s; // Stack to store operators
    string postfix = ""; // Resulting postfix expression

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isOperand(ch)) {
            postfix += ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If the character is ')', pop and add to postfix until '(' is encountered
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        }
        // Operator encountered
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

