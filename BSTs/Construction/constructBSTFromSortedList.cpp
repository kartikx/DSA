// Given a Sorted Linked List, construct the BST.
// https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node(int val) {
            this->val = val;
        }

        int val;
        Node* left;
        Node* right;
};

Node* constructBSTUtil(list<int>::iterator& it, int n) {

    if (n <= 0) {
        return NULL;
    }

    Node* leftTree = constructBSTUtil(it, n/2);

    Node* root = new Node(*it);
    it++;
    root->left = leftTree;

    Node* rightTree = constructBSTUtil(it, n - n/2 - 1);
    root->right = rightTree;

    return root;
}

Node* constructBST(list<int>& l) {
    auto it = l.begin();
    return constructBSTUtil(it, l.size());
}

void printTree(Node* root) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = (int) q.size();
        for (int i=0; i<size; i++) {
            Node* curr = q.front(); q.pop();
            if (curr) {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    list<int> l{1, 2, 3, 4, 5, 6, 7, 8};
    Node* root = constructBST(l);
    printTree(root);
}