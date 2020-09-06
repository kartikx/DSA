/**
 * Given the Keys of 2 Nodes, write a function to swap those two.
 * Note that it wouldn't be a good idea to just swap the data,
 * because that might be time consuming. A much better approach
 * is to modify the links.
 */

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

void swapNodes(Node*& head, int key1, int key2) {
    if (!head) {
        return;
    }

    Node* prevX = NULL, *currX = head;
    Node* prevY = NULL, *currY = head;

    Node* curr = head;

    while (curr->next) {
        if (curr->next->val == key1) {
            prevX = curr;
            currX = curr->next;
        }

        else if (curr->next->val == key2) {
            prevY = curr;
            currY = curr->next;
        }

        curr = curr->next;
    }

    if (!currY || !currX) {
        cout << "Keys don't exist in List" << endl;
        return;
    }

    if (!prevX) {
        prevY->next = currX;
        head = currY;
    }
    else if (!prevY) {
        prevX->next = currY;
        head = currX;
    }
    else {
        prevX->next = currY;
        prevY->next = currX;
    }

    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

int main() {
    vector<int> values{3, 1, 5, 7, 9};
    Node* head = makeList(values);
    swapNodes(head, 7, 3);
    printList(head);
}