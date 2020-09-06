// Write the Partition Function for Quick Sort on a Singly Linked List.
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

Node* getRight(Node* h) {
    if (!h)
        return NULL;
    
    while (h->next) {
        h = h->next;
    }
    return h;
}

// Logic: Push the bigger elements to the end, and skip over the smaller elements.
// List gets modified so L and R will change.
Node* partition(Node*& l, Node*& r) {
    if (!l || !r || l == r) {
        return NULL;
    }

    Node* tail = r;
    Node* pivot = r;
    Node* curr = l;
    Node* prev = NULL;
    Node* newHead = NULL;

    while (curr != r) {
        if (curr->val < r->val) {
            if (!newHead) {
                newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else {
            if (prev) {
                prev->next = curr->next;
            }
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (!newHead) {
        newHead = r;
    }

    r = tail;
    l = newHead;

    return pivot;
}

Node* quickSortUtil(Node* l, Node* r) {
    if (l == r || !l || !r) {
        return l;
    }

    // This call modifies l and r.
    Node* pivot = partition(l, r);

    if (pivot != l) {
        Node* temp = l;
        while (temp && temp->next != pivot) {
            temp = temp->next;
        }
        // To treat it as a linkedlist of it's own.
        temp->next = NULL;
        l = quickSortUtil(l, temp);
        temp = getRight(l);
        temp->next = pivot;
    }
    pivot->next = quickSortUtil(pivot->next, r);
    return l;
}

Node* quickSort(Node* h) {
    Node* r = getRight(h);
    if (!h || !r)
        return NULL;
    h = quickSortUtil(h, r);
    return h;
}

int main() {
    vector<int> values{4, 3, 5, 2, 8};
    Node* h = makeList(values);
    h = quickSort(h);
    printList(h);
}