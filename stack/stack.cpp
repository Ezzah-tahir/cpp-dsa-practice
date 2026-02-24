#include "stack.h"
#include <iostream>
#include <string>
#include<cmath>
#include <cctype> // For isdigit function
using namespace std;

// Push function
void mystack::push(int data) {
    if (isfull()) {
        cout << "Stack overflow\n";
        return;
    }
    l[++top] = data;
}

// Pop function
int mystack::pop() {
    if (isempty()) {
        cout << "Stack underflow\n";
        return -1;
    }
    return l[top--];
}

// Display function
void mystack::display() {
    if (isempty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements:\n";
    for (int i = 0; i <= top; i++) {
        cout << l[i] << endl;
    }
}

// Is full function
bool mystack::isfull() {
    return top == MAX - 1;
}

// Is empty function
bool mystack::isempty() {
    return top == -1;
}

// Peek function
int mystack::peek() {
    if (isempty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return l[top];
}

// Function to check precedence
int mystack::prec(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

// Function to convert infix to postfix
string mystack::infinixToPostfix(string s) {
    string res;
    mystack st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) { // Operand
            res += c;
        }
        else if (c == '(') { // Left parenthesis
            st.push(c);
        }
        else if (c == ')') { // Right parenthesis
            while (!st.isempty() && st.peek() != '(') {
                res += (char)st.pop();
            }
            if (!st.isempty()) st.pop(); // Remove '('
        }
        else { // Operator
            while (!st.isempty() && prec(st.peek()) >= prec(c)) {
                res += (char)st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isempty()) {
        res += (char)st.pop();
    }

    return res;
}
// fucntion for evaluation of infinix expression


int mystack::evaluation(string s) {
    mystack st; // Stack for evaluation
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) { // Check if the character is a digit
            st.push(s[i] - '0'); // Convert character to numeric value
        }
        else { // Operator case
            if (st.isempty()) {
                cout << "Error: Insufficient operands\n";
                return -1; // Error handling for invalid input
            }

            int op2 = st.peek();
            st.pop();
            if (st.isempty()) {
                cout << "Error: Insufficient operands\n";
                return -1; // Error handling for invalid input
            }

            int op1 = st.peek();
            st.pop();

            switch (s[i]) {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '/':
                if (op2 == 0) {
                    cout << "Error: Division by zero\n";
                    return -1; // Error handling for division by zero
                }
                st.push(op1 / op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '^':
                st.push(pow(op1, op2)); // Power operation
                break;
            default:
                cout << "Error: Unknown operator '" << s[i] << "'\n";
                return -1; // Error handling for invalid operator
            }
        }
    }

    if (st.isempty()) {
        cout << "Error: Evaluation failed\n";
        return -1; // Error handling for empty stack
    }

    return st.peek(); 
}
