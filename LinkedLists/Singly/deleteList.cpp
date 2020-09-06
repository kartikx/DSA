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

void deleteList(Node*& head) {
    if (!head) {
        return;
    }
    deleteList(head->next);
    delete(head);
    head = NULL;
}

int main() {
    vector<int> v = {2, 1, 4};
    Node* head = makeList(v);
    deleteList(head);
    cout << head->val << endl;
}