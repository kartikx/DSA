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

Node* partition(Node*& l, Node*& r) {
    if (!l || l == r) {
        return l;
    }

    Node* tail = r;
    Node* pivot = tail;
    Node* newHead = NULL;

    Node* temp = l;
    Node* prev = NULL;

    while (temp != pivot) {
        if (temp->val < pivot->val) {
            if (!prev) {
                newHead = temp;
            }
            prev = temp;
            temp = temp->next;
        }
        else {
            if (prev) {
                prev->next = temp->next;
            }
            else {
                newHead = temp->next;
            }
            Node* orgNext = temp->next;
            tail->next = temp;
            temp->next = NULL;
            tail = tail->next;
            temp = orgNext;
        }
    }

    l = newHead;
    r = tail;
    return pivot;
}

void printList(Node* root) {
    if (!root) {
        cout << "Empty List" << endl;
        return;
    }

    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

void foo(Node*& head, Node*& tail) {
    tail = tail->next;
    cout << head->val << " " << head->next->val << endl;
}

int main() {
    map<int, int> m;
    m.insert({1, 2});
    auto it = m.begin();
    it--;
    cout << it->first << " " << it->second << endl;
}