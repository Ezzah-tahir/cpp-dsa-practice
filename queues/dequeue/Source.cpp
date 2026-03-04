#include"Header.h"
#include<iostream>
using namespace std;
deq::deq() :front(-1), rear(-1) {}

bool deq::isFull() {
    return rear == MAX - 1;
}

bool deq::isEmpty() {
    return (rear == -1) && (front == -1);
}

void deq::insertAtFront(int data) {
    if (front <= 0) {
        cout << "Cannot insert at front (overflow)" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        front--;
    }
    Q[front] = data;
}

void deq::insertAtRear(int data) {
    if (isFull()) {
        cout << "Cannot insert at rear (overflow)" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    Q[rear] = data;
}

int deq::removeFront() {
    if (isEmpty()) {
        cout << "Cannot remove from front (underflow)" << endl;
        return -1;
    }
    int data = Q[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
    return data;
}

int deq::removeRear() {
    if (isEmpty()) {
        cout << "Cannot remove from rear (underflow)" << endl;
        return -1;
    }
    int data = Q[rear];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
    return data;
}

void deq::display() {
    if (isEmpty()) {
        cout << "Deque is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
    cout << "front: " << front << endl;
    cout << " rear:" << rear << endl;
}
