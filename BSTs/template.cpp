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

Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (root->val >= val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
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
        root = insert(root, value);
    return root;
}

Node* search(Node* root, int val) {
    if (!root || root->val == val) {
        return root;
    }

    if (root->val >= val) {
        return search(root->left, val);
    }

    return search(root->right, val);
}

// Returns the Successor of Root.
Node* findSuccessor(Node* root) {
    if (!root || !root->right) {
        return NULL;
    }

    Node* temp = root->right;

    while (temp->left) {
        temp = temp->left;
    }

    return temp;
}

Node* deleteNode(Node* root, int val) {
    if (!root) {
        throw runtime_error("Value does not exist");
        return NULL;
    }

    if (root->val == val) {
        if (root->left && root->right) {
            // Find succcessor (left-most child in right Tree, can have atmost 1 child).
            Node* succ = findSuccessor(root);
            int succ_val = succ->val;
            deleteNode(root, succ_val);
            root->val = succ_val;
            return root;
        }

        else if (root->left) {
            delete root;
            return root->left;
        }

        // Handles both root->right and NULL.
        else {
            delete root;
            return root->right;
        }
    }

    else if (root->val > val) {
        root->left = deleteNode(root->left, val);
    }
    else {
        root->right = deleteNode(root->right, val);
    }

    return root;
}

int main() {
    vector<int> v{2, 1, 3, 4, 5};
    Node* root = buildTree(v);

    printTree(root);

    cout << endl << endl;

    root = deleteNode(root, 3);

    printTree(root);
}