// Given a BST, convert it into Greater Sum Tree, so that the structure remains same,
// However each Node contains the sum of all nodes greater than it (in value).
// https://www.geeksforgeeks.org/transform-bst-sum-tree/

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

void modifyBST(Node* root, vector<int>& inorder, int& index) {
    if (!root) {
        return;
    }

    modifyBST(root->left, inorder, index);
    root->val = inorder[index];
    index++;
    modifyBST(root->right, inorder, index);
}

/**
 * Approach 1
 * Store the Inorder Traversal.
 * Convert it into a Suffix Sum Array.
 * Re-Traverse, and modify each value with the corresponding index in Sum Array.
 */
// void convertBST(Node* root) {
//     vector<int> inorder;
//     inorderTraversal(root, inorder);
//     vector<int> sumList(inorder.size(), 0);

//     for (int i=sumList.size()-2; i >=0 ; --i) {
//         sumList[i] = sumList[i+1] + inorder[i+1];
//     }

//     int index=0;
//     modifyBST(root, sumList, index);
// }

void convertBSTUtil(Node* root, int& sum) {
    if (!root) {
        return;
    }

    convertBSTUtil(root->right, sum);
    int orig = root->val;
    root->val = sum;
    sum += orig;
    convertBSTUtil(root->left, sum);
    return;
}

/**
 * Approach 2
 * Perform a Reverse Inorder.
 * This would ensure that whenever you're at an Index,
 * You have traversed the Nodes bigger than it.
 * Maintain a sum counter, and use it to replace the value.
 */
void convertBST(Node* root) {
    int sum = 0;
    return convertBSTUtil(root, sum);
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
    printTree(root);
    cout << "-------------" << endl;
    convertBST(root);
    printTree(root);
}