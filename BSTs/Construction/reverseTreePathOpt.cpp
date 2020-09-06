/**
 * Elegant Approach to Reverse Path in BST
 * using Queues.
 * The important property leveraged here is that
 * in a BST you are aware of the path which will
 * need to be traversed.
 * So keep track of the nodes visited so far, when you
 * reach the last node, replace it's value with the first
 * node which was seen. So a FIFO structure required.
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
        Node* left;
        Node* right;
};

void reversePathBSTUtil(Node* root, int key, queue<int>& path) {

    if (!root) {
        return ;
    }

    path.push(root->val);

    if (key < root->val) {
        reversePathBSTUtil(root->left, key, path);
    }

    else if (key > root->val) {
        reversePathBSTUtil(root->right, key, path);
    }

    root->val = path.front();
    path.pop();
}

void inorderTraversal(Node* root) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void reversePathBST(Node* root, int key) {
    queue<int> path;
    reversePathBSTUtil(root, key, path);
    inorderTraversal(root);
    cout << endl;
}

Node* createStaticBST() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    return root;
}

int main() {
    Node* root = createStaticBST();
    reversePathBST(root, 70);
}