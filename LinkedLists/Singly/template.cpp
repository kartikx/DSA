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

void prepend(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void append(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (!head) {
        return;
    }
    Node* last = head;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

void insertAfter(Node*& prevNode, int val) {
    Node* newNode = new Node(val);
    if (!prevNode) {
        return;
    }

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Deletes the first occurence of val.
void deleteNode(Node*& head, int val) {
    if (!head) {
        return;
    }

    Node* curr(head);

    if (curr->val == val) {
        head = head->next;
        delete curr;
        return;
    }

    while (curr->next && curr->next->val != val) {
        curr = curr->next;
    }

    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return;
    }
    cout << "Value not found" << endl;
    return;
}

void deleteNodePosition(Node*& head, int position) {
    if (!head) {
        return;
    }
    Node* temp = head;
    if (position == 1 ){
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = NULL;
    while (temp && position != 1) {
        prev = temp;
        temp = temp->next;
        position--;
    }

    if (!temp) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

int main() {
    vector<int> values = {2, 1, 4, 7, 5};
    Node* head = makeList(values);
    printList(head);
    deleteNodePosition(head, 1);
    printList(head);
    deleteNodePosition(head, 20);
    printList(head);
    deleteNodePosition(head, 4);
    printList(head);
    deleteNodePosition(head, 2);
    printList(head);
}