#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node(int val, Node* parent) {
            this->val = val;
            this->parent = parent;
        }

        int val;
        Node* left;
        Node* right;
        Node* parent;
};

Node* insert(Node* root, Node* parent, int val) {
    if (!root) {
        return new Node(val, parent);
    }

    if (root->val >= val) {
        root->left = insert(root->left, root, val);
    }
    else {
        root->right = insert(root->right, root, val);
    }

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

Node* buildTree(vector<int> values) {
    Node* root = NULL;
    if (values.empty()) {
        return root;
    }

    for (int value : values)
        root = insert(root, NULL, value);
    return root;
}

/**
 * @returns The Minimum Node of the subtree rooted at @param root.
 */
Node* findMinimum(Node* root) {
    Node* temp = root;

    while (temp->left) {
        temp = temp->left;
    }

    return temp;
}

/**
 * @param root: The root of the Tree.
 * @param key: The node searching for.
 */
Node* findSuccessor(Node* root, int key) {
    if (!root) {
        return NULL;
    }

    if (root->val == key) {
        if (root->right) {
            return findMinimum(root->right);
        }
        else {
            Node* y = root->parent;
            Node* x = root;

            while (y && x == y->right) {
                x = y;
                y = y->parent;
            }
            return y;
        }
    }

    else if (root->val > key) {
        return findSuccessor(root->left, key);
    }

    return findSuccessor(root->right, key);
}

int main() {
    vector<int> values{10, 6, 15, 4, 8, 12, 27};
    Node* root = buildTree(values);

    for (auto x : values) {
        cout << x << " " << findSuccessor(root, x)->val << endl;
    }
}