#include "queue.h"
#include <iostream>
using namespace std;

bool myqueue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool myqueue::isFull() {
    return rear == MAX - 1;
}

void myqueue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue overflow" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    q[rear] = data;
}

int myqueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int item = q[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
    return item;
}

void myqueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Displaying: ";
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " - ";
    }
    cout << endl;
}

int myqueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return q[front];
}