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

// Time Complexity: O(N^2).
Node* constructBST(vector<int>& preorder, int l, int r) {
    if (l > r) {
        return NULL;
    }

    Node* newNode = new Node(preorder[l]);

    int i;
    for (i=l; i<=r; i++)
        if (preorder[i] > preorder[l])
            break;

    newNode->left = constructBST(preorder, l+1, i-1);
    newNode->right = constructBST(preorder, i, r);

    return newNode;
}

Node* constructBSTUtil(vector<int>& preorder, int& index, int min, int max) {

    // This is probably a risky move, considering how index is a shared variable and may
    // be changed from everywhere. However, due to the nature of Preorder, we can be sure
    // that the current key is the current index.
    int key = preorder[index];
    Node* root = NULL;

    if (key >= min && key <= max) {
        index++;

        root = new Node(key);

        root->left = constructBSTUtil(preorder, index,  min, key);

        root->right = constructBSTUtil(preorder, index, key, max);
    }

    return root;
}

// O(N) Approach
Node* constructBSTOpt(vector<int>& preorder) {
    if (preorder.empty()) {
        return NULL;
    }
    int index = 0;
    return constructBSTUtil(preorder, index, INT_MIN, INT_MAX); 
}

Node* constructBSTIter(vector<int>& preorder) {
    stack<Node*> s;
    Node* root = NULL;
    for (int i=0; i<preorder.size(); ++i) {
        int currVal = preorder[i];

        Node* newNode = new Node(currVal);

        if (!root) {
            root = newNode;
            s.push(newNode);
            continue;
        }

        if (currVal < s.top()->val) {
            s.top()->left = newNode;
            s.push(newNode);
        }
        
        else {
            Node* temp;
            while (!s.empty() && s.top()->val < currVal) {
                temp = s.top();
                s.pop();
            }

            temp->right = newNode;
            s.push(newNode);
        }
    }

    return root;
}

int main() {
    vector<int> v{10, 6, 4, 8, 15, 12, 27};
    Node* root = constructBSTIter(v);

    printTree(root);
}