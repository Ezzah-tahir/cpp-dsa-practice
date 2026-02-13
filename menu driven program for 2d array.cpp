#include <iostream>
#include <string>
using namespace std;

// 1. Array Creation
void read(int arr[][30], int& rows, int& cols, int maxRows, int maxCols) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    if (rows > maxRows || cols > maxCols) {
        cout << "Dimensions exceeded the maximum size!" << endl;
        rows = cols = 0; // Reset to avoid undefined behavior
    }
    else {
        cout << "Enter the elements row by row:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr[i][j];
            }
        }
    }
}

// 2. Displaying Array
void display(int arr[][30], int rows, int cols) {
    cout << "Displaying elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// 3. Insertion
// a. At Start
void insertAtStart(int arr[][30], int& rows, int cols, int maxRows) {
    if (rows < maxRows) {
        for (int i = rows; i > 0; i--) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }
        cout << "Enter the elements for the new row: ";
        for (int j = 0; j < cols; j++) {
            cin >> arr[0][j];
        }
        rows++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}

// b. At End
void insertAtEnd(int arr[][30], int& rows, int cols, int maxRows) {
    if (rows < maxRows) {
        cout << "Enter the elements for the new row: ";
        for (int j = 0; j < cols; j++) {
            cin >> arr[rows][j];
        }
        rows++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}

// c. At Specific Position
void insertAtPosition(int arr[][30], int& rows, int cols, int maxRows, int pos) {
    if (pos < 1 || pos > rows + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (rows < maxRows) {
        for (int i = rows; i >= pos; i--) { // Shift rows down
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }
        cout << "Enter the elements for the new row: ";
        for (int j = 0; j < cols; j++) {
            cin >> arr[pos - 1][j];
        }
        rows++;
    }
    else {
        cout << "Array is already full!" << endl;
    }
}

// 4. Searching
bool search(int arr[][30], int rows, int cols, int target, int& row, int& col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// 5. Average of the 2D Array
int average(int arr[][30], int rows, int cols) {
    if (rows == 0 || cols == 0) return 0; // Avoid division by zero
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum / (rows * cols);
}

// 6. Deletion
// a. At Start
void deleteAtStart(int arr[][30], int& rows, int cols) {
    if (rows == 0) {
        cout << "Array is already empty!" << endl;
    }
    else {
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i + 1][j];
            }
        }
        rows--;
    }
}

// b. At End
void deleteAtEnd(int& rows) {
    if (rows == 0) {
        cout << "Array is already empty!" << endl;
    }
    else {
        rows--;
    }
}

// c. Delete at Specific Position
void deleteAtPosition(int arr[][30], int& rows, int cols, int pos) {
    if (rows == 0) {
        cout << "Array is already empty!" << endl;
        return;
    }
    if (pos < 1 || pos > rows) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < rows - 1; i++) { // Shift rows up
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    rows--;
}

// Main Function
int main() {
    const int MAX_ROWS = 30, MAX_COLS = 30;
    int array[MAX_ROWS][MAX_COLS], rows = 0, cols = 0, pos, element, choice, searchData, searchRow, searchCol;
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
            read(array, rows, cols, MAX_ROWS, MAX_COLS);
            arrayCreated = (rows > 0 && cols > 0); // Ensure valid array creation
            break;
        }
        case 2: {
            if (!arrayCreated) {
                cout << "Array is not created yet! Please create an array first (Option 1)." << endl;
            }
            else {
                display(array, rows, cols);
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
                switch (insertChoice) {
                case 'a': insertAtStart(array, rows, cols, MAX_ROWS); break;
                case 'b': insertAtEnd(array, rows, cols, MAX_ROWS); break;
                case 'c':
                    cout << "Enter the position: ";
                    cin >> pos;
                    insertAtPosition(array, rows, cols, MAX_ROWS, pos);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }
                display(array, rows, cols);
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
                case 'a': deleteAtStart(array, rows, cols); break;
                case 'b': deleteAtEnd(rows); break;
                case 'c':
                    cout << "Enter the position: ";
                    cin >> pos;
                    deleteAtPosition(array, rows, cols, pos);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }
                display(array, rows, cols);
            }
            break;
        }
        case 5: {
            cout << "Enter target value: ";
            cin >> searchData;
            if (search(array, rows, cols, searchData, searchRow, searchCol)) {
                cout << "Element found at position (" << searchRow + 1 << ", " << searchCol + 1 << ")" << endl;
            }
            else {
                cout << "Element not found!" << endl;
            }
            break;
        }
        case 6: {
            cout << "Average: " << average(array, rows, cols) << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}