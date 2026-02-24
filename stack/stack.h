#pragma once
#pragma once
#include<string>
#define MAX 10
using namespace std;
class mystack {
	//data memebers
	int l[MAX];
	int top;
public: //memeber functions
	mystack() :top(-1) {}
	void push(int);
	int pop();
	void display();
	bool isfull();
	bool isempty();
	int peek();
	int prec(char);
	string infinixToPostfix(string s);
	int evaluation(string s);
};
