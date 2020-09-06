#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node(int val) {
            this->val = val;
        }
        int val;
        Node* next;
};

Node* appendNode(Node* last, int val) {
    Node* newNode = new Node(val);

    if (!last) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

Node* makeList(vector<int> values) {
    if (values.empty())
        return NULL;
    
    Node* last = NULL;
    for (auto x : values) {
        last = appendNode(last, x);
    }

    return last;
}

void printList(Node* last) {
    Node* temp = last;
    while (temp->next && temp->next != last) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
    cout << endl;
}

int main() {
    Node* last = makeList({1, 2, 3, 4, 5});    
}