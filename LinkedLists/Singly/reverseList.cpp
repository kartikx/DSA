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

Node* reverseList(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

Node* reverseListIter(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;

    /*
            p c n
        1 2 4 5
    */
    while (curr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
            next = next->next;
    }

    return prev;
}

int main() {
    vector<int> values{1, 4, 5, 7};
    Node* head = makeList(values);
    head = reverseListIter(head);
    printList(head);
    head = reverseListIter(head);
    printList(head);
}