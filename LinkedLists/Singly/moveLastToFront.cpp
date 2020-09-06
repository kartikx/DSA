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

void moveLastToFront(Node*& head) {
    if (!head || !head->next) {
        return;
    }

    Node* curr = head;

    // Curr stores prev of last element.
    while (curr->next->next) {
        curr = curr->next;
    }

    Node* last = curr->next;
    curr->next = NULL;
    last->next = head;
    head = last;
}

int main() {
    vector<int> values{2, 1, 3, 5, 7,6 ,9};
    Node* head = makeList(values);
    moveLastToFront(head);
    printList(head);
}