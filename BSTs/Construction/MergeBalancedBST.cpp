// Given 2 Balanced BSTs, Merge them.
// https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

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

Node* constructBSTFromSortedArray(vector<int>::iterator& it, int n) {
    if (n <= 0) {
        return NULL;
    }

    Node* leftTree = constructBSTFromSortedArray(it, n/2);

    Node* root = new Node(*it);
    it++;
    root->left = leftTree;

    Node* rightTree = constructBSTFromSortedArray(it, n-n/2-1);
    root->right = rightTree;

    return root;
}

Node* mergeBalancedBSTS(Node* root1, Node* root2) {
    vector<int> inorder1, inorder2;
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);
    vector<int> inorder(inorder1.size() + inorder2.size(), 0);
    merge(inorder1.begin(), inorder1.end(), inorder2.begin(), inorder2.end(), inorder.begin());

    Node* root;
    auto it = inorder.begin();
    root = constructBSTFromSortedArray(it, inorder.size());
    return root;
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
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {10, 16, 18, 20, 24};

    auto it1=v1.begin(), it2=v2.begin();
    Node* root1 = constructBSTFromSortedArray(it1, v1.size());
    Node* root2 = constructBSTFromSortedArray(it2, v2.size());

    Node* root = mergeBalancedBSTS(root1, root2);
    printTree(root);
}