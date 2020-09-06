#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node(int val) {
            this->val = val;
        }
        int val;
        Node* next;
};

int cycleLength(Node* head) {
    // First find a Node in the cycle using Floyd Algorithm.
    Node* fast = head;
    Node* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
        slow = slow->next;
    }

    if (fast != slow) {
        return -1;
    }

    int count = 1;
    fast = slow->next;
    while (fast != slow) {
        count++;
        fast = fast->next;
    }

    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);    
    head->next->next->next->next = head->next;

    cout << cycleLength(head) << endl;
}