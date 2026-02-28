#pragma once
#pragma once 
#include<iostream> 
#define MAX 10 
using namespace std;
class myqueue {
	int q[MAX];
	int front, rear;
public:
	myqueue() :front(-1), rear(-1) {}
	bool isEmpty();
	bool isFull();
	int peek();
	void enqueue(int data);
	int dequeue();
	void display();
};