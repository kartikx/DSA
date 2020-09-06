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

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void pairwiseSwap(Node*& head) {
    if (!head) 
        return;
    
    Node* curr = head;
    Node* prev = NULL;

    while (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = curr;

        if (!prev) {
            head = temp;
        }
        else {
            prev->next = temp;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    vector<int> values{2, 1, 3, 5, 7, 9};
    Node* head = makeList(values);
    pairwiseSwap(head);
    printList(head);
}