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

Node* makeList(vector<int>& values) {
    Node* head = NULL;
    Node* curr = NULL;
    for (auto x : values) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            curr = head;
        }
        else {
            curr->next = newNode;
            curr = curr->next;    
        }
    }
    return head;
}

Node* getMiddle(Node*& head) {
    Node *slow = head , *fast = head;

    // Returns the first middle for even nodes.
    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast)
            slow = slow->next;
    }

    return slow;
}

int main() {
    vector<int> values = {7, 4, 3, 1};
    Node* head = makeList(values);
    cout << getMiddle(head)->val << endl;
}