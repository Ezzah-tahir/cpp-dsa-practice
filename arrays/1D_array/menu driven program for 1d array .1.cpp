#include <iostream>
#include<string>
using namespace std;
// 1. Array Creation
void read(int arr[], int& n, int max) {
    cout << "Enter the number of elements of the array: ";
    cin >> n;
    if (n > max) {
        cout << "Number of elements exceeded the maximum size!" << endl;
        n = 0; // Reset n to avoid undefined behavior
    }
    else {
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
}
// 2. Displaying Array
void display(int arr[], int n) {
    cout << "Displaying elements of the array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 3. Insertion
// a. At Start
void insertAtStart(int arr[], int& n, int element, int max) {
    if (n < max) {
        for (int i =n-1; i >=0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = element;
        n++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}
// b. At End
void insertAtEnd(int arr[], int& n, int element, int max) {
    if (n < max) {
        arr[n] = element;
        n++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}
// c. At Specific Position
void insertAtPosition(int arr[], int& n, int max, int pos, int element) {
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (n < max) {
        for (int i = n-1; i >= pos-1; i--) { // Shift elements right
            arr[i+1] = arr[i];
        }
        arr[pos - 1] = element;
        n++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}
// 4. Searching
int search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (target == arr[i]) {
            return i + 1; // Returning 1-based index
        }
    }
    return -1;
}
// 5. Average
int average(int arr[], int n) {
    if (n == 0) return 0; // Avoid division by zero
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}
// 6. Deletion
// a. At Start
void deleteAtStart(int arr[], int& n) {
    if (n == 0) {
        cout << "Array is already empty!" << endl;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
}
// b. At End
void deleteAtEnd(int& n) {
    if (n == 0) {
        cout << "Array is already empty!" << endl;
    }
    else {
        n--; // Simply reduce the size
    }
}
// c. Delete at Specific Position
void deleteAtPosition(int arr[], int& n, int pos) {
    if (n == 0) {
        cout << "Array is already empty!" << endl;
        return;
    }
    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) { // Shift elements left
        arr[i] = arr[i + 1];
    }
    n--;
}
// Main Function
int main() {
    const int MAX = 30;
    int array[MAX], n = 0, pos, element, choice, searchData;
    bool arrayCreated = false;
    char insertChoice;

    cout << "---------Menu---------" << endl;
    do {
        cout << "\n1. Create Array\n"
            << "2. Display Array\n"
            << "3. Insert Element\n"
            << "4. Delete Element\n"
            << "5. Search Element\n"
            << "6. Display Average\n"
            << "7. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            read(array, n, MAX);
            arrayCreated = (n > 0); // Ensure valid array creation
            break;
        }
        case 2: {
            if (!arrayCreated) {
                cout << "Array is not created yet! Please create an array first (Option 1)." << endl;
            }
            else {
                display(array, n);
            }
            break;
        }
        case 3: {
            if (!arrayCreated) {
                cout << "Array is not created yet! Please create an array first (Option 1)." << endl;
            }
            else {
                cout << "\na. Insert at Start\nb. Insert at End\nc. Insert at Specific Position\nEnter your choice: ";
                cin >> insertChoice;
                cout << "Enter the element to insert: ";
                cin >> element;
                switch (insertChoice) {
                case 'a': insertAtStart(array, n, element, MAX); break;
                case 'b': insertAtEnd(array, n, element, MAX); break;
                case 'c':
                    cout << "Enter the position: ";
                    cin >> pos;
                    insertAtPosition(array, n, MAX, pos, element);
                    break;
                default: cout << "Invalid choice!" << endl;
                }
                display(array, n);
            }
            break;
        }
        case 4: {
            if (!arrayCreated) {
                cout << "Array is not created yet! Please create an array first (Option 1)." << endl;
            }
            else {
                cout << "\na. Delete at Start\nb. Delete at End\nc. Delete at Specific Position\nEnter your choice: ";
                cin >> insertChoice;
                switch (insertChoice) {
                case 'a': deleteAtStart(array, n); break;
                case 'b': deleteAtEnd(n); break;
                case 'c':
                    cout << "Enter the position: ";
                    cin >> pos;
                    deleteAtPosition(array, n, pos);
                    break;
                default: cout << "Invalid choice!" << endl;
                }
                display(array, n);
            }
            break;
        }
        case 5: {
            cout << "Enter target value: ";
            cin >> searchData;
            int result = search(array, n, searchData);
            cout << (result == -1 ? "Element not found!" : "Element found at position " + to_string(result)) << endl;
            break;
        }
        case 6: {
            cout << "Average: " << average(array, n) << endl;
            break;
        }
        }
    } while (choice != 7);
    return 0;
}