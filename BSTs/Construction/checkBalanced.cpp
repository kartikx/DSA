// Given a Tree Check if It is Balanced.
// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

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

/**
 * One basic idea would be to check if left is balanced, if right is balanced,
 * and then compute the difference of their heights.
 * However, i think the height calculation could be done within the call itself,
 * instead of calling it separately.
 */ 

bool checkBalancedUtil(Node* root, int& h) {
    // Height of single Node Tree is 1. Height = number of Nodes in this implementation.
    if (!root) {
        h = 0;
        return true;
    }

    int lh = 0, rh=0;

    bool b1 = checkBalancedUtil(root->left, lh);
    bool b2 = checkBalancedUtil(root->right, rh);

    h = max(lh, rh) + 1;

    cout << "Height of " << root->val << " is: " << h << endl;
    return b1 && b2 && abs(rh-lh) <= 1;
}

bool checkBalanced(Node* root) {

    int h = 0;
    return checkBalancedUtil(root, h);
}

Node* constructBT() {
    Node* root = new Node(10);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->right = new Node(15);
    root->right->right = new Node(5);
    return root;
}

int main() {
    Node* root = constructBT();
    cout << checkBalanced(root);
}