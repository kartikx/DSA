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

Node* createStaticBT() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right = new Node(6);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(9);
    root->right->right = new Node(3);
    return root;
}

void reverseTreePathBTUtil(Node* root, int key, int& nextpos, int level, bool& found, unordered_map<int, int>& m) {
    if (!root) {
        return;
    }

    m[level] = root->val;

    cout << level << ":" << m[level] << endl;

    if (root->val == key) {
        found = true;
        root->val = m[nextpos];
        nextpos++;
        return;
    }

    reverseTreePathBTUtil(root->left, key, nextpos, level+1, found, m);

    if (!found) {
        reverseTreePathBTUtil(root->right, key, nextpos, level+1, found, m);
    }

    if (found) {
        root->val = m[nextpos];
        nextpos++;
    }

    return;
}

void reverseTreePathBT(Node* root, int key) {
    int nextpos = 0;
    bool found = false;
    unordered_map<int, int> m;
    reverseTreePathBTUtil(root, key, nextpos, 0, found, m);
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
    Node* root = createStaticBT();
    reverseTreePathBT(root, 9);
    printTree(root);
}
