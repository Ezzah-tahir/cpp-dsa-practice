#include<iostream>
using namespace std;
struct node {
	int m;
	node* next;
};
//creating node
node* create() {
	node* head = NULL,
		* curr = NULL,
		* prev = NULL;
	char choice;
	do {
		curr = new node;
		curr->next = NULL;
		cout << "enter the data of the node: ";
		cin >> curr->m;
		if (head == NULL) {
			head = prev = curr;
		}
		else {
			prev->next = curr;
			prev = curr;
		}
		cout << "do you want to enter another node" << endl;
		cin >> choice;
		if (choice != 'Y' && choice != 'y') {
			break;
		}
	} while (true);
	return head;
}
// displaying
void display(node* head) {
	node* curr = head;
	while (curr != NULL) {
		cout << curr->m << " -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}
// insertion at start of the node
node* insertAtStart(node* head) {
	node* newnode = NULL;
	newnode = new node;
	newnode->next = NULL;
	cout << "enter the data of new node: ";
	cin >> newnode->m;
	if (head == NULL) {
		head = newnode; 
	}
	else {
		newnode->next = head;
		head = newnode;
	}
	return head;
}
// insertion at end of the node 
node* insertAtEnd(node* head) {
	node* curr = NULL;
	node* newnode = NULL;
	newnode = new node;
	newnode->next = NULL;
	cout << "enter the data of new node: ";
	cin >> newnode->m;
	if (head == NULL) {
		head = newnode;
	}
	else {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newnode;
	}
	return head;
}
// insertion at the given location by user
node* insertAtLocation(node* head, int location) {
	if (location <= 1) {
		cout << "location is invalid" << endl;
	}
	node* curr = NULL;
	node* newnode = NULL;
	newnode = new node;
	newnode->next = NULL;
	cout << "enter the data of new node: ";
	cin >> newnode->m;
	if (head == NULL) {
		head = newnode;
	}
	else {
		curr = head;
		for (int i = 1; i < location - 1; i++) {
			curr = curr->next;
		}
		newnode->next = curr->next;
		curr->next = newnode;
	}
	return head;
}
//deletion at start
node* deleteAtStart(node* head) {
	node* curr = NULL;
	if (head == NULL) {
		cout << "list is already empty" << endl;
		return head;
	}
	else {
		curr = head;
		head = head->next;
		delete curr;
	}
	return head;
}

// deletion at end
node* deleteAtEnd(node* head) {
	node* curr = NULL,
		* prev = NULL;
	// case 1 : the list is empty
	if (head == NULL) {
		cout << "list is already empty" << endl;
		return head;
	}
	// case 2: the list has only one node
	if (head->next == NULL) {
		delete head;
		head = NULL;
		cout << "only one node is deleted, list is now empty" << endl;
		return head;
	}
	// case 3: the list has more than one node
	else {
		curr = prev = head;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		delete curr;
	}
	return head;
}
// deletion at the given location by the user
node* deleteAtLocation(node* head, int location) {
	node* curr = NULL;
	node* prev = NULL;
	// case : the list has only one node
	if (head->next == NULL) {
		delete head;
		head = NULL;	
	}
	// case : the list has multiple node and deletion is supposed to be in the middle of the nodes
	else {
		curr = head;
		for (int i = 1; i < location; i++) {
			prev = curr;
			curr = curr->next;
		}
	
		prev->next = curr->next;
		delete curr;
	}
	return head;
}
//main function
int main() {
	int choice, insertChoice, location, dltChoice;
	node* head = NULL;
	node* newnode = NULL;
	cout << "\n------MENU-----\n" << endl;
	do {
		cout << "\n1.create" << endl
			<< "2.display" << endl
			<<"3.insert"<<endl
			<<"4.delete"<<endl
			<< "5.exit" << endl
			<< "enter your choice" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			head = create();
			break;
		}
		case 2: {
			if (head==NULL) {
				cout << "create a linked list first (option 1)" << endl;
			}
			else {
				display(head);
			}
			break;
		}
			  //INSERTION MENU
		case 3: {
			do {
				if (head == NULL) {
					cout << "create a linked list first (option 1)" << endl;
					continue;
				}
				cout << "\n -----Inserting Menu-----" << endl
					<< "1.insert at start of the list" << endl
					<< "2.insert at the end of the list" << endl
					<< "3.insert at given location" << endl
					<< "4.exit insertion menu" << endl
					<< "enter your choice" << endl;
				cin >> insertChoice;
				cout << "before insertion: " << endl;
				display(head);
				switch (insertChoice) {
				case 1: {
					head = insertAtStart(head);
					break;
				}
				case 2: {
					head = insertAtEnd(head);
					break;
				}
				case 3: {
					cout << "enter location for insertion: ";
					cin >> location;
					head = insertAtLocation(head, location);
					break;
				}
				case 4: {
					cout << "exiting insertion menu, returnig to the main menu" << endl;
					break;
				}
				default:
					cout << "invalid option plz try again" << endl;
					break;
				}
				if (insertChoice >= 1 && insertChoice <= 3) {
					cout << "after insertion: " << endl;
					display(head);
				}
			} while (insertChoice != 4);
			

			break;
		}
			  //insertion menu ends here

			  // deletion menu 
		case 4: {
			do {
				if (head == NULL) {
					cout << "create a linked list first (option 1)" << endl;
					continue;
				}
				cout << "\n -----Deletion Menu-----" << endl
					<< "1.delete at start of the list" << endl
					<< "2.delete at the end of the list" << endl
					<< "3.delete at given location" << endl
					<< "4.exit deletion menu" << endl
					<< "enter your choice" << endl;
				cin >> dltChoice;
				cout << "before deletion: " << endl;
				display(head);
				switch (dltChoice) {
				case 1: {
					head = deleteAtStart(head);
					break;
				}
				case 2: {
					head = deleteAtEnd(head);
					break;
				}
				case 3: {
					cout << "enter location for deletion: ";
					cin >> location;
					head = deleteAtLocation(head, location);
					break;
				}
				case 4: {
					cout << "exiting deletion menu , returning to the main menu" << endl;
					break;
				}
				default:
					cout << "invalid option plz try again" << endl;
					break;
				}
				if (dltChoice >= 1 && dltChoice <= 3) {
					cout << "after deletion: " << endl;
					display(head);
				}
			} while (dltChoice != 4);


			break;
		}
			  //deletion menu ends here
		default:
			cout << "invalid option plz try again" << endl;
		}
	} while (choice != 5);
		
	return 0;
}