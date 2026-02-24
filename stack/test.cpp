#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    mystack stack; // Create stack object
    int choice;    // To store menu choice

    do {
        // Display menu
        cout << "\n--------Menu--------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Peek (Top Element)\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Check if Stack is Empty\n";
        cout << "7. Convert Infix to Postfix\n";
        cout << "8. Evaluate Infix Expression\n"; // New menu option
        cout << "9. Exit\n"; // Update exit option
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
        case 1: { // Push
            int value;
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2: { // Pop
            int poppedValue = stack.pop();
            if (poppedValue != -1)
                cout << "Popped value: " << poppedValue << endl;
            break;
        }
        case 3: { // Display
            cout << "Current stack elements:\n";
            stack.display();
            break;
        }
        case 4: { // Peek
            int topValue = stack.peek();
            if (topValue != -1)
                cout << "Top element: " << topValue << endl;
            break;
        }
        case 5: { // Check if full
            if (stack.isfull())
                cout << "The stack is full.\n";
            else
                cout << "The stack is not full.\n";
            break;
        }
        case 6: { // Check if empty
            if (stack.isempty())
                cout << "The stack is empty.\n";
            else
                cout << "The stack is not empty.\n";
            break;
        }
        case 7: { // Convert Infix to Postfix
            string infix, postfix;
            cout << "Enter an infix expression: ";
            cin >> infix;
            postfix = stack.infinixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;
            break;
        }
        case 8: { // Evaluate Infix Expression
            string infix;
            cout << "Enter an infix expression to evaluate: ";
            cin >> infix;

            // Step 1: Convert infix to postfix
            string postfix = stack.infinixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;

            // Step 2: Evaluate the postfix expression
            int result = stack.evaluation(postfix);
            if (result != -1) // Check if evaluation was successful
                cout << "Evaluation result: " << result << endl;
            break;
        }
        case 9: { // Exit
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9); // Repeat until user chooses to exit

    return 0;
}
