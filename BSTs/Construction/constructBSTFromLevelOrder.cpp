// Given a Level Order Traversal, Construct the BST.
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

bool inRange(int val, pair<int, int> range) {
    if (val >= range.first && val <= range.second) {
        return true;
    }

    return false;
}

/**
 * Intuitive Approach
 * Use a Queue, but in addition to storing the Nodes,
 * also store the Ranges. This will allow you to predict
 * whether the incoming node is to be left child/right child
 * or no child at all.
 * 
 * O(N) Space O(N) Time.
 */
Node* constructBST(vector<int>& levelOrder) {
    if (levelOrder.empty()) {
        return NULL;
    }

    Node* root = new Node(levelOrder[0]);
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {INT_MIN, INT_MAX}});
    
    int index = 1;
    while (!q.empty() && index < levelOrder.size()) {
        auto currNode = q.front().first;
        auto range = q.front().second;
        q.pop();

        if (inRange(levelOrder[index], {range.first, currNode->val})) {
            Node* newNode = new Node(levelOrder[index]);
            currNode->left = newNode;
            q.push({newNode, {range.first, currNode->val}});
            index++;
        }

        if (inRange(levelOrder[index], {currNode->val, range.second})) {
            Node* newNode = new Node(levelOrder[index]);
            currNode->right = newNode;
            q.push({newNode, {currNode->val, range.second}});
            index++;
        }
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

int main() {
    vector<int> v{7, 4, 12, 3, 6, 8, 1, 5, 10};
    Node* root = constructBST(v);

    printTree(root);
}