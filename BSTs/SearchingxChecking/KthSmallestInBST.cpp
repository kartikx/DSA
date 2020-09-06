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

int findKthSmallestUtil(Node* root, int k, int& count) {
    if (!root) {
        return -1;
    }

    int a1 = findKthSmallestUtil(root->left, k, count);
    int a2 = -1;
    if (a1 == -1) {
        count++;
        if (k == count) {
            return root->val;
        }
        a2 = findKthSmallestUtil(root->right, k, count);
        return a2;
    }

    return a1;
}

int findKthSmallest(Node* root, int k) {
    int count(0);
    return findKthSmallestUtil(root, k, count);
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
    cout << findKthSmallest(root, 3);
}