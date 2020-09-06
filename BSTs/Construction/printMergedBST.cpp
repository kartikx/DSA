// Given two Balanced BSTs, print the sorted representation of the merged trees
// Do in O(h1 + h2) space, and O(n1 + n2) time.
// https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/

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

void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
    return;
}

void printMergedBST(Node* root1, Node* root2) {
    if (!root1 && !root2) {
        return ;
    }

    if (root1 && root2) {
        printMergedBST(root1->left, root2->left);
        cout << min(root1->val, root2->val) << " " << max(root1->val, root2->val) << " ";
        printMergedBST(root1->right, root2->right);
    }

    else if (root1) {
        printMergedBST(root1->left, root2);
        cout << root1->val << " ";
        printMergedBST(root1->right, root2);
    }

    else {
        printMergedBST(root1, root2->left);
        cout << root2->val << " ";
        printMergedBST(root1, root2->right);
    }

    return;
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
    Node* root1 = new Node(8);
    root1->left = new Node(2);
    root1->right = new Node(10);
    root1->left->left = new Node(1);

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->left->left = new Node(0);

    printMergedBST(root1, root2);

}