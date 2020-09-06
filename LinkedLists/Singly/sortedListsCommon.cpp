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

void appendNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }

    curr->next = newNode;
    return;
}

Node* sortedListsCommon(Node*& head1, Node*& head2) {
    if (!head1 || !head2) {
        return NULL;
    }

    Node* head = NULL;
    Node* curr1 = head1, *curr2 = head2;
    while (curr1 && curr2) {
        while(curr1 && curr2 && curr1->val != curr2->val) {
            if (curr1->val < curr2->val) 
                curr1 = curr1->next;
            else {
                curr2 = curr2->next;
            }
        }

        // At this point, I've either reached the end, or equal values.
        if (curr1 && curr2) {
            appendNode(head, curr1->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    return head;
}

int main() {
    vector<int> values1{1, 2, 4, 7};
    vector<int> values2{2, 4, 8};
    Node* h1 = makeList(values1);
    Node* h2 = makeList(values2);

    Node* h = sortedListsCommon(h1, h2);
    printList(h);
}