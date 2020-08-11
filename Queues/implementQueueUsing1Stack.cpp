#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
My original Approach:
The private queue is such that the top of the stack
is present at the end of the queue.
Push O(1)
Pop O(N), uses reversal operations.

class MyStack {
    public:
        MyStack() {

        }

        // Push is O(1), top of stack present at back of queue.
        void push(int val) {
            q.push(val);
        }

        // To pop, reverse the queue, remove the first, reverse the queue.
        void pop() {
            reverseQueue();
            q.pop();
            reverseQueue();
        }

        void reverseQueue()
        {
            if (q.empty())
            {
                return;
            }

            int currVal = q.front();
            q.pop();

            reverseQueue();

            q.push(currVal);
        }

        void printQueue()
        {   
            int size = q.size();
            for (int i=0;i<size;i++)
            {
                cout << q.front() << " ";
                q.push(q.front());
                q.pop();
            }

            cout << endl;
        }
    private:
        queue<int> q;
};
*/

/*
GfG approach.
Top of Stack at front of Queue, so removal O(1).
Insertion O(N), first insert the element at the end,
then move all elements to the back.
*/
class MyStack {
    public:
        MyStack() {
        }

        void push(int val) {
            int size = q.size();
            q.push(val);

            for (int i=0; i<size; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }

        void pop() {
            q.pop();
        }

        void printQueue() {
            int size = q.size();

            for (int i=0; i<size; i++) {
                cout << q.front() << " ";
                q.push(q.front());
                q.pop();
            }

            cout << endl;
        }

    private:
        queue<int> q;
};

int main() {
    MyStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.printQueue();
    q.pop();
    q.printQueue();
}