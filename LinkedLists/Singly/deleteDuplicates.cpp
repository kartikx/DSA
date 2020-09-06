// Sorted LL remove duplicates.

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
// You don't really need separate pointers, if you're only comparing immediate values.
void deleteDuplicates(Node*& head) {
    Node* curr = head;

    if (!curr) {
        return;
    }

    while (curr->next) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }
}

int main() {
    vector<int> values{1, 1, 1, 2, 2, 3, 4, 5};
    Node* head = makeList(values);
    deleteDuplicates(head);
    printList(head);
}