#include<iostream>
using namespace std;

// Doubly Linked List Node
struct node {
    int m;
    node* next;
    node* prev;
};

// Creating DLL
node* create() {
    node* head = NULL;
    node* curr = NULL;
    node* prev = NULL;
    char choice;
    do {
        curr = new node;
        curr->next = curr->prev = NULL;
        cout << "Enter the data of the node: ";
        cin >> curr->m;
        if (head == NULL) {
            head = prev = curr;
        }
        else {
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
        cout << "Do you want to enter another node (Y/N)? ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y') break;
    } while (true);
    return head;
}

// Display forward
void display(node* head) {
    node* curr = head;
    while (curr != NULL) {
        cout << curr->m << " <-> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// Insert at start
node* insertAtStart(node* head) {
    node* newnode = new node;
    cout << "Enter data of new node: ";
    cin >> newnode->m;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) head->prev = newnode;
    head = newnode;
    return head;
}

// Insert at end
node* insertAtEnd(node* head) {
    node* newnode = new node;
    cout << "Enter data of new node: ";
    cin >> newnode->m;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return head;
    }
    node* curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newnode;
    newnode->prev = curr;
    return head;
}

// Insert at given location
node* insertAtLocation(node* head, int location) {
    if (location <= 1) {
        cout << "Invalid location" << endl;
        return head;
    }
    node* newnode = new node;
    cout << "Enter data of new node: ";
    cin >> newnode->m;
    newnode->next = newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return head;
    }

    node* curr = head;
    for (int i = 1; i < location - 1 && curr->next != NULL; i++)
        curr = curr->next;

    newnode->next = curr->next;
    newnode->prev = curr;
    if (curr->next != NULL) curr->next->prev = newnode;
    curr->next = newnode;

    return head;
}

// Delete at start
node* deleteAtStart(node* head) {
    if (head == NULL) {
        cout << "List is already empty" << endl;
        return head;
    }
    node* curr = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete curr;
    return head;
}

// Delete at end
node* deleteAtEnd(node* head) {
    if (head == NULL) {
        cout << "List is already empty" << endl;
        return head;
    }
    node* curr = head;
    while (curr->next != NULL) curr = curr->next;

    if (curr->prev != NULL) curr->prev->next = NULL;
    else head = NULL; // Only one node

    delete curr;
    return head;
}

// Delete at given location
node* deleteAtLocation(node* head, int location) {
    if (head == NULL) return head;
    node* curr = head;
    for (int i = 1; i < location && curr != NULL; i++)
        curr = curr->next;
    if (curr == NULL) {
        cout << "Location out of bounds" << endl;
        return head;
    }
    if (curr->prev != NULL) curr->prev->next = curr->next;
    else head = curr->next; // Deleting first node
    if (curr->next != NULL) curr->next->prev = curr->prev;
    delete curr;
    return head;
}

// Main Function
int main() {
    int choice, insertChoice, location, dltChoice;
    node* head = NULL;

    do {
        cout << "\n------MENU-----\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            head = create();
            break;
        case 2:
            if (head == NULL) cout << "Create a linked list first (option 1)" << endl;
            else display(head);
            break;
        case 3:
            do {
                if (head == NULL) {
                    cout << "Create a linked list first (option 1)" << endl;
                    break;
                }
                cout << "\n--Insertion Menu--\n1. At Start\n2. At End\n3. At Location\n4. Exit\nEnter choice: ";
                cin >> insertChoice;
                if (insertChoice == 1) head = insertAtStart(head);
                else if (insertChoice == 2) head = insertAtEnd(head);
                else if (insertChoice == 3) {
                    cout << "Enter location: ";
                    cin >> location;
                    head = insertAtLocation(head, location);
                }
                else if (insertChoice == 4) break;
                else cout << "Invalid choice!" << endl;

                cout << "Updated list: ";
                display(head);
            } while (insertChoice != 4);
            break;
        case 4:
            do {
                if (head == NULL) {
                    cout << "Create a linked list first (option 1)" << endl;
                    break;
                }
                cout << "\n--Deletion Menu--\n1. At Start\n2. At End\n3. At Location\n4. Exit\nEnter choice: ";
                cin >> dltChoice;
                if (dltChoice == 1) head = deleteAtStart(head);
                else if (dltChoice == 2) head = deleteAtEnd(head);
                else if (dltChoice == 3) {
                    cout << "Enter location: ";
                    cin >> location;
                    head = deleteAtLocation(head, location);
                }
                else if (dltChoice == 4) break;
                else cout << "Invalid choice!" << endl;

                cout << "Updated list: ";
                display(head);
            } while (dltChoice != 4);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        }

    } while (choice != 5);

    return 0;
}
