/**
 * Given a BST, find the LCA of 2 nodes which exist in the Tree.
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

void search(Node* root, int key, string& s) {
    if (!root || root->val == key) {
        return;
    }

    if (key < root->val) {
        s += '0';
        return search(root->left, key, s); 
    }

    s += '1';
    return search(root->right, key, s);
}

Node* getNode(Node* root, string& s) {
    Node* temp = root;
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '0') {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return temp;
}

Node* LCA(Node* root, int key1, int key2) {
    string s1(""), s2("");

    search(root, key1, s1);
    search(root, key2, s2);

    string commonString("");
    int i=0, j=0;
    while (i<s1.length() && j<s2.length() && s1[i] == s2[j]) {
        commonString += s1[i];
        i++;
        j--;
    }

    return getNode(root, commonString);
}

Node* LCA2(Node* root, int key1, int key2) {
    if (!root) {
        return NULL;
    }

    if (key1 < root->val && key2 < root->val) {
        return LCA2(root->left, key1, key2);
    }

    else if (key1 > root->val && key2 > root->val) {
        return LCA2(root->right, key1, key2);
    }

    // In this question, we are guaranteed that keys exist in Tree
    // If they may not, then at this point you should also check
    // if they exist using a search.
    return root;
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
    cout << LCA2(root, 35, 7)->val << endl;
    cout << LCA2(root, 35, 15)->val << endl;
    cout << LCA2(root, 2, 7)->val << endl;
    cout << LCA2(root, 15, 4)->val << endl;
}