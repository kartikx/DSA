// Remove all duplicates from an unsorted LL.

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

// Using two loops.
void deleteDuplicatesIter(Node*& head) {
    if (!head) {
        return;
    }

    Node* curr = head;
    while (curr) {
        Node* fast = curr;
        while (fast->next) {
            if (fast->next->val == curr->val) {
                Node* temp = fast->next;
                fast->next = fast->next->next;
                delete temp;
            }
            else {
                fast = fast->next;
            }
        }
        curr = curr->next;
    }
}

void deleteDuplicates(Node*& head) {
    Node* curr = head;
    if (!curr) {
        return;
    }

    unordered_set<int> distinctNodes;
    distinctNodes.insert(curr->val);
    while (curr->next) {
        if (distinctNodes.count(curr->next->val) > 0) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else {
            distinctNodes.insert(curr->next->val);
            curr = curr->next;
        }
    }
}

int main() {
    vector<int> values{2, 1, 2, 1, 3, 2, 4, 3, 5, 4};
    Node* head = makeList(values);
    deleteDuplicatesIter(head);
    printList(head);
}