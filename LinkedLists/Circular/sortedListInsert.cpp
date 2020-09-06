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
    cout << temp->val << " ";
    temp = temp->next;
    while (temp != last) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
    cout << endl;
}

int findLength(Node* head) {
    if (!head) {
        return 0;
    }

    int count = 1;
    Node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    return count;
}

Node* insertSortedList(Node* last, int val) {
    Node* newNode = new Node(val);

    // ! Use last to add.

    if (!last) {
        last = newNode;
        newNode->next = last;
        return last;
    }

    Node* temp = last->next;
    Node* prev = NULL;
    while (temp->val < val && temp != last) {
        prev = temp;
        temp = temp->next;
    }

    // At this point either temp->val >= val or temp = last.
    if (temp->val >= val) {
        newNode->next = temp;
        if (prev) {
            prev->next = newNode;
        }
        else {
            last->next = newNode;
        }
    }
    // insert at end.
    else {
        newNode->next = temp->next;
        temp->next = newNode;
        last = newNode;
    }

    return last;
}

int main() {
    Node* last = NULL;
    vector<int> v{2, 1, 7, 3, 6, 8};
    for (int x : v) {
        last = insertSortedList(last, x);
        printList(last->next);
    }
}
