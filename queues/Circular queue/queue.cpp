#include"Header.h" 
#include<iostream> 
using namespace std;
bool myqueue::isEmpty() {
	return (front == -1) && (rear == -1);
}
bool myqueue::isFull() {
	return rear == MAX - 1;
}
void myqueue::enqueue(int data) {
	if (front == -1 && rear == -1) {
		front = rear = 0;
	}
	else if ((front == (rear + 1) % MAX)) {
		cout << "circular queue overflow" << endl;
		return;
	}
	else {
		rear = (rear + 1) % MAX;
	}
	q[rear] = data;
}
int myqueue::dequeue() {
	if (isEmpty()) {
		cout << "circular queue underflow" << endl;
		return -1;
	}
	int item = q[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % MAX;
	}
}
void myqueue::display() {
	cout << "displaying: " << endl;
	for (int i = front; i <= rear; i++) {
		cout << q[i] << " - ";
	}
	cout << endl;
}
int myqueue::peek() {
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		return -1;
	}
	return q[front];
}