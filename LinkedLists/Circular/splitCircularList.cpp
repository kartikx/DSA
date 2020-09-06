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
    while (temp->next && temp->next != last) {
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

Node* splitList(Node*& head) {
    if (!head) {
        return head;
    }

    Node* fast = head->next;
    Node* slow = head;

    while (fast != head && fast->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // cout << "Mid value: " << slow->val << endl;
    Node* temp = slow->next;
    Node* head2 = temp;
    slow->next = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = head2;
    return head2;
}

int main() {
    Node* head = makeList({1, 2, 3, 4, 5})->next;
    Node* head2 = splitList(head);
    printList(head);
    printList(head2);
}