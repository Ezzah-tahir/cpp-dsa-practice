#include"Header.h"
#include<iostream>
using namespace std;
int main() {
    deq d1;

    d1.insertAtRear(100);
    d1.insertAtRear(200);
    d1.insertAtRear(300);

    cout << "Deque contents: ";
    d1.display();

    cout << "Removed from front: " << d1.removeFront() << endl;
    cout << "Removed from rear: " << d1.removeRear() << endl;

    cout << "Deque contents after removals: ";
    d1.display();

    cout << "Removed from front: " << d1.removeFront() << endl;
    d1.display();


    d1.insertAtFront(400);
    cout << "inserted at front" << endl;
    d1.display();



    return 0;

}