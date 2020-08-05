#include <iostream>
using namespace std;
class Node {
    public:
        Node(int val) 
            :val(val),
             next(NULL)
        {
        }
        int val;
        Node* next;
};

/**
 * Generally you would use a Top and a Bottom node,
 * but here I'm optimizing by only having a single bottom node.
 * Next of Bottom will be the Top
 */
class Stack {
    public:
        Stack() {
            bottom = NULL;
            size = 0;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            if (size == 0) {
                newNode->next = newNode;
                bottom = newNode;
            }
            /*
                newNode->next = bottom->next
                bottom->next = newNode;
                For size = 0 bottom = NULL so set bottom = newNode.
            */
           else {
                newNode->next = bottom->next;
                bottom->next = newNode;
            }
            size++;
        }

        int pop() {
            if (!bottom) {
                return -1;
            }
            int val = bottom->next->val;

            if (bottom->next == bottom) {
                bottom = NULL;
                delete bottom;
                return val;
            }

            Node* temp = bottom->next;
            bottom->next = bottom->next->next;
            temp = NULL;
            delete temp;
            size--;
            return val;
        }

        void mergeStack(Stack s2) {
            // swap(this->bottom->next, s2.bottom->next);
            auto temp = this->bottom->next;
            this->bottom->next = s2.bottom->next;
            s2.bottom->next = temp;
            this->bottom = s2.bottom;
        }

        Node* bottom;
        int size;
};

int main() {
    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    Stack s2;
    s2.push(7);
    s2.push(8);
    s2.push(9);

    s.mergeStack(s2);
    // cout << s.bottom->val << " " << s.bottom->next->val << endl;
    while(s.bottom)
        cout << "Remove: " << s.pop() << endl;
}