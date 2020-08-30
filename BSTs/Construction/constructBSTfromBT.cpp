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

void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
    return;
}

void constructBSTUtil(Node* root, vector<int>& inorder, int& index) {
    if (!root) {
        return;
    }

    constructBSTUtil(root->left, inorder, index);
    root->val = inorder[index];
    index++;
    constructBSTUtil(root->right, inorder, index);
    return;
}

Node* constructBST(Node* root) {

    // First get the Inorder Traversal of the BT.
    vector<int> inorder;
    inorderTraversal(root, inorder);
    sort(inorder.begin(), inorder.end());
    for_each(inorder.begin(), inorder.end(), [](const int& x) {cout << x << " " ;});
    cout << endl;
    int index = 0;
    constructBSTUtil(root, inorder, index);

    return root;
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
    printTree(root);
    cout << "---------------" << endl;
    root = constructBST(root);
    printTree(root);
}