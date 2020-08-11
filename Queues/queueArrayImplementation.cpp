/*
Implement a Queue using the standard Array
based implementation.
To make efficient use of Space, we're gonna
use a Circular Approach
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
        MyQueue(int capacity)
        {
            this->front = this->size = 0;
            this->capacity = capacity;
            this->arr = new int[capacity*sizeof(int)];
            this->rear = capacity - 1; // starts off from the end.
        }

        void push(int val)
        {
            if (this->size == this->capacity) {
                cout << "Queue Overflow" << endl;
                return;
            }

            this->rear = (this->rear + 1) % (this->capacity);
            this->arr[this->rear] = val;
            this->size++;
        }

        void pop()
        {
            if (this->size == 0) {
                cout << "Queue underflow" << endl;
                return;
            }

            this->front = (this->front + 1) % (this->capacity);
            this->size--;
        }

        void printQueue()
        {
            cout << "Front is: " << this->front << " Rear is: " << this->rear << endl;
            for (int i=0; i<this->capacity; i++)
            {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
    private:
        int front, rear, size;
        unsigned capacity;
        int* arr;
};

/*
Deque using Circular Array Implementation
Initially Front=0, Rear = N-1;
insertFront()
not possible if size = N;
else front = front-1; if 0 => N-1;
apply val. size++
removeFront()
not possible if size=0;
else front = front+1 %  if front-1>0, else N + front - 1;

*/

int main() {
    MyQueue q(5);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(7);
    q.push(10);
    q.pop();
    q.push(11);
    q.printQueue();
}