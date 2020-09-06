/**
 * Convert a Binary Tree to a Circular Doubly Linked List
 * In Constant Space.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node(int x) {
            this->val = x;
        }
        int val;
        Node* left, *right;
};

// L or R may be NULL. Not both.
Node* concatenate(Node* l, Node* r) {
    if (!l)
        return r;
    if (!r)
        return l;
    
    Node* endL = l->left;
    Node* endR = r->left;

    l->left = endR;
    r->left = endL;
    endL->right = r;
    endR->right = l;

    return l;
}
Node* convert(Node* root) {
    if (!root) {
        return NULL;
    }

    Node* leftTree = convert(root->left);
    Node* rightTree = convert(root->right);

    root->left = root->right = root;

    return concatenate(concatenate(leftTree, root), rightTree);
}

int main() {
    // construct tree.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    root = convert(root);

    Node* temp = root;
    while (temp->right != root) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << temp->val << " ";
}