#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    myqueue q1;   // queue object
    int dlt;      // for dequeued item
    int data;     // for input data
    int choice;   // menu choice

    cout << "------- Queue Menu -------" << endl;

    do {
        cout << endl;
        cout << "1. Enqueue" << endl
            << "2. Dequeue" << endl
            << "3. Peek" << endl
            << "4. Check if the queue is full" << endl
            << "5. Check if the queue is empty" << endl
            << "6. Display" << endl
            << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter data to enqueue: ";
            cin >> data;
            q1.enqueue(data);
            break;
        }
        case 2: {
            dlt = q1.dequeue();
            if (dlt != -1) {
                cout << "Dequeued item: " << dlt << endl;
            }
            break;
        }
        case 3: {
            int frontItem = q1.peek();
            if (frontItem != -1) {
                cout << "Front item: " << frontItem << endl;
            }
            break;
        }
        case 4: {
            if (q1.isFull()) {
                cout << "The queue is full." << endl;
            }
            else {
                cout << "The queue is not full." << endl;
            }
            break;
        }
        case 5: {
            if (q1.isEmpty()) {
                cout << "The queue is empty." << endl;
            }
            else {
                cout << "The queue is not empty." << endl;
            }
            break;
        }
        case 6: {
            q1.display();
            break;
        }
        case 7: {
            cout << "Exiting the program." << endl;
            break;
        }
        default:
            cout << "Error: Invalid choice. Please try again!" << endl;
        }
    } while (choice != 7);

    return 0;
}