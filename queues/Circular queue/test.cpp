#include "Header.h" 
#include <iostream> 
using namespace std;

int main() {
    myqueue q1;
    int dlt;
    int data;
    int choice;
    cout << "-------Menu-------" << endl;
    do {
        cout << endl;
        cout
            << "1. Enqueue" << endl
            << "2. Dequeue" << endl
            << "3. Peek" << endl
            << "4. Check if the queue is full" << endl
            << "5. Check if the queue is empty" << endl
            << "6. display" << endl
            << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Enqueue option 
            cout << "Enter data to enqueue: ";
            cin >> data;
            q1.enqueue(data);
            break;
        }
        case 2: {
            // Dequeue option 
            dlt = q1.dequeue();
            if (dlt != -1) {
                cout << "Dequeued item: " << dlt << endl;
            }
            break;
        }
        case 3: {
            // Peek option 
            int frontItem = q1.peek();
            if (frontItem != -1) {
                cout << "Front item: " << frontItem << endl;
            }
            break;
        }
        case 4: {
            // Check if the queue is full 
            if (q1.isFull()) {
                cout << "The circular queue is full." << endl;
            }
            else {
                cout << "The circular queue is not full." << endl;
            }
            break;
        }
        case 5: {
            // Check if the queue is empty 
            if (q1.isEmpty()) {
                cout << "The circular queue is empty." << endl;
            }
            else {
                cout << "The circular queue is not empty." << endl;
            }
            break;
        }
        case 6: {
            cout << "displaying:" << endl;
            q1.display();
            break;
        }
        case 7: {
            // Exit option 
            cout << "Exiting the program." << endl;
            break;
        }
        default:
            // Invalid choice 
            cout << "Error: Invalid choice. Please try again!" << endl;
        }
    } while (choice != 7);

    return 0;
}
