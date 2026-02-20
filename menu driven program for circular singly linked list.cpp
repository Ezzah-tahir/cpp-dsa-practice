#include<iostream>
using namespace std;

// Circular Singly Linked List Node
struct node {
    int m;
    node* next;
};

// Create Circular Singly Linked List
node* create() {
    node* head = NULL;
    node* curr = NULL;
    node* temp = NULL;
    char choice;

    do {
        curr = new node;
        cout << "Enter the data of the node: ";
        cin >> curr->m;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
            curr->next = head;   // Point to itself
        }
        else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = curr;
            curr->next = head;   // Make circular
        }

        cout << "Do you want to enter another node (Y/N)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return head;
}

// Display
void display(node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    do {
        cout << temp->m << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

// Insert at Start
node* insertAtStart(node* head) {
    node* newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->m;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return head;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;

    return head;
}

// Insert at End
node* insertAtEnd(node* head) {
    node* newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->m;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return head;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;

    return head;
}

// Delete at Start
node* deleteAtStart(node* head) {
    if (head == NULL) {
        cout << "List empty\n";
        return head;
    }

    if (head->next == head) {
        delete head;
        return NULL;
    }

    node* temp = head;
    node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    delete temp;
    return head;
}

// Delete at End
node* deleteAtEnd(node* head) {
    if (head == NULL) {
        cout << "List empty\n";
        return head;
    }

    if (head->next == head) {
        delete head;
        return NULL;
    }

    node* temp = head;
    node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    delete temp;

    return head;
}

// Main Function
int main() {
    int choice;
    node* head = NULL;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Create\n2. Display\n3. Insert at Start\n4. Insert at End\n5. Delete at Start\n6. Delete at End\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            head = create();
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insertAtStart(head);
            break;
        case 4:
            head = insertAtEnd(head);
            break;
        case 5:
            head = deleteAtStart(head);
            break;
        case 6:
            head = deleteAtEnd(head);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}