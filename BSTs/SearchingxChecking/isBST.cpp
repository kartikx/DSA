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

bool isBSTUtil(Node* root, int min, int max) {
    if (!root) {
        return true;
    }

    if (!(root->val > min && root->val < max)) {
        return false;
    }

    return isBSTUtil(root->left, min, root->val) && isBSTUtil(root->right, root->val, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/**
 * Alternative Approach: Perform Inorder Traversal,
 * if the resulting array is not sorted, it's not a BST.
 * Instead of using Aux. Space, you may instead keep track
 * of the last seen node.
 */

bool isBST2Util(Node* root, int& lastVal) {
    if (!root) {
        return true;
    }

    bool b1 = isBST2Util(root->left, lastVal);
    if (lastVal >= root->val) {
        return false;
    }
    lastVal = root->val;
    bool b2 = isBST2Util(root->right, lastVal);

    return b1 && b2;
}

bool isBST2(Node* root) {
    int lastVal = INT_MIN;
    return isBST2Util(root, lastVal); 
}

Node* createStaticBST() {
    Node* root = new Node(11);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right = new Node(29);
    root->right->left = new Node(15);
    root->right->right = new Node(40);
    root->right->right->left = new Node(35);
    return root;
}

int main() {
    Node* root = createStaticBST();
    cout << isBST2(root) << endl;
}