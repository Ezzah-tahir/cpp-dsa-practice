#include<iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node* parent;

    node(int val) : data(val), left(NULL), right(NULL), parent(NULL) {}
};


// INSERT FUNCTION
node* insert(node* root, int key) {

    node* newNode = new node(key);
    node* y = NULL;
    node* x = root;

    while (x != NULL) {
        y = x;
        if (key < x->data)
            x = x->left;
        else
            x = x->right;
    }

    newNode->parent = y;

    if (y == NULL)
        root = newNode;
    else if (key < y->data)
        y->left = newNode;
    else
        y->right = newNode;

    return root;
}


// SEARCH
node* search(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}


// MINIMUM
node* min(node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}


// MAXIMUM
node* max(node* root) {
    while (root->right != NULL)
        root = root->right;

    return root;
}


// SUCCESSOR
node* successor(node* x) {

    if (x->right != NULL)
        return min(x->right);

    node* y = x->parent;

    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}


// PREDECESSOR
node* predecessor(node* x) {

    if (x->left != NULL)
        return max(x->left);

    node* y = x->parent;

    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}



int main() {

    node* root = NULL;
    int choice, value;

    do {

        cout << "\n----- BST MENU -----\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
        cout << "5. Find Successor\n";
        cout << "6. Find Predecessor\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2: {
            cout << "Enter value to search: ";
            cin >> value;

            node* result = search(root, value);

            if (result != NULL)
                cout << "Node found: " << result->data << endl;
            else
                cout << "Node not found\n";
            break;
        }

        case 3: {
            node* m = min(root);
            if (m != NULL)
                cout << "Minimum value: " << m->data << endl;
            break;
        }

        case 4: {
            node* m = max(root);
            if (m != NULL)
                cout << "Maximum value: " << m->data << endl;
            break;
        }

        case 5: {
            cout << "Enter node value to find successor: ";
            cin >> value;

            node* x = search(root, value);

            if (x != NULL) {
                node* s = successor(x);

                if (s != NULL)
                    cout << "Successor is: " << s->data << endl;
                else
                    cout << "No successor exists\n";
            }
            else
                cout << "Node not found\n";

            break;
        }

        case 6: {
            cout << "Enter node value to find predecessor: ";
            cin >> value;

            node* x = search(root, value);

            if (x != NULL) {
                node* p = predecessor(x);

                if (p != NULL)
                    cout << "Predecessor is: " << p->data << endl;
                else
                    cout << "No predecessor exists\n";
            }
            else
                cout << "Node not found\n";

            break;
        }

        }

    } while (choice != 7);

}