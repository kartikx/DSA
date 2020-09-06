/**
 * Inorder Traversal of a BST without using
 * Stack / Recursion.
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

void MorrisTraversal(Node* root) {
    if (!root) {
        return;
    }

    while (root) {
        if (!root->left) {
            cout << root->val << " ";
            root = root->right;
        }

        else {
            Node* pred = root->left;
            // ! Search for Pred in Left Tree, take care to avoid Infinite Loop.
            while (pred->right && pred->right != root) {
                pred = pred->right;
            }

            if (!pred->right) {
                pred->right = root;
                root = root->left;
            }
            else {
                pred->right = NULL;
                cout << root->val << " ";
                root = root->right;
            }
        }
    }

    cout << endl;
}

Node* createStaticBST() {
    Node* root = new Node(15);
    root->left = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(10);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(14);

    root->right = new Node(20);
    root->right->right = new Node(25);
    root->right->right->left = new Node(22);
    return root;
}

int main() {
    Node* root = createStaticBST();
    MorrisTraversal(root);
}