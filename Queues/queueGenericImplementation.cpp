#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

template <class T>
class MyQueue {
    public:
        MyQueue() {
            front = nullptr;
            end = nullptr;
        }

        void push(int val) {
            MyNode* newNode = new MyNode(val);
            if (end != nullptr){
                end->next = myNode;
            }
            end = myNode;
            if (front == nullptr) {
                first = myNode;
            }
        }

        void pop() {
            if (front == nullptr) {
                cout << "Empty Queue" ;
                return;
            }

            cout << "Removing: " << front->val << endl;
            MyNode* temp = front;
            delete temp;
            front = front->next;
            // implies empty.
            if (front == nullptr) {
                end = front;
            }    
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void printQueue() {
            MyNode* temp = front;
            while (temp) {
                cout << temp->val << " ";
                temp = temp->next;
            }
        }
    private:
        class MyNode {
            public:
                MyNode(int val) {
                    this->val = val;
                }
                int val;
                MyNode* next;
        };

        MyNode* front;
        MyNode* end;
};

int main() {
    MyQueue<int> mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.pop();
    mq.pop();
    mq.pop();
    mq.printQueue();
}