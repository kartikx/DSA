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

bool getPathUtil(Node* root, int key, vector<int>& path) {
    if (root->val == key) {
        return true;
    }

    bool b1 = false, b2 = false;
    if (root->left) {
        path.push_back(root->left->val);
        b1 = getPathUtil(root->left, key, path);
        if (!b1) {
            path.pop_back();
        }
    }

    if (root->right) {
        path.push_back(root->right->val);
        b2 = getPathUtil(root->right, key, path);
        if (!b2) {
            path.pop_back();
        }
    }

    return (b1 || b2);
}

vector<int> getPath(Node* root, int key) {
    vector<int> path;
    if (!root) {
        return path;
    }
    path.push_back(root->val);
    getPathUtil(root, key, path);
    return path;
}

vector<int> getPathBST(Node* root, int key) {
    vector<int> path;
    Node* temp = root;

    while (temp) {
        cout << temp->val << endl;
        path.push_back(temp->val);
        if (temp->val == key) {
            break;
        }
        else if (temp->val > key) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    if (!temp) {
        return vector<int>();
    }

    return path;
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

void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
    return;
}

void reverseTreePathBST(Node* root, int key) {
    if (!root)
        return;

    // For normal BTs using getPathBT instead.
    vector<int> path = getPathBST(root, key);
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int i=0, j=path.size()-1;

    while (i < j) {
        auto it1 = equal_range(inorder.begin(), inorder.end(), path[i]);
        auto it2 = equal_range(inorder.begin(), inorder.end(), path[j]);
        iter_swap(it1.first, it2.first);

        i++;
        j--;
    }

    for (auto x : inorder) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Node* root = createStaticBST();
    reverseTreePathBST(root, 4);
}