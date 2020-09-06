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

// Tail Recursive Method.
void findLengthUtil(Node*& head, int& len) {
    if (!head) {
        return;
    }

    len++;
    findLengthUtil(head->next, len);
}

int findLength(Node*& head) {
    int len = 0;
    findLengthUtil(head, len);
    return len;
}

int main() {
    vector<int> values = {2, 1, 4, 7, 3, 8, 9};
    Node* head = makeList(values);

    cout << findLength(head) << endl;
}