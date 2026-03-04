#pragma once
#include<iostream>
#define MAX 10
using namespace std;

class deq{
int Q[MAX];
int front, rear;

public:
deq(); // Constructor
void insertAtRear(int data);
void insertAtFront(int data);
int removeRear();
int removeFront();
void display();
bool isEmpty();
bool isFull();
};


