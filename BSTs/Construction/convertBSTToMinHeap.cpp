/**
 * Convert a given BST into a Min-Heap in place.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The basic idea is to do Inorder to get the Sorted Order,
 * store it, and then re-traverse in level order fashion
 * to get the Min-Heap. However this would require O(N)
 * Aux. Space.
 * In such cases, you may instead convert the BST In Place
 * to a Sorted Linked List. You can then perform traversal
 * on the Linked List, to get the Min-Heap.
 */

class Node {
    public:
        Node(int val) {
            this->val = val;
        }

        int val;
        Node* left;
        Node* right;
};

void convertBSTToLL(Node* root, Node*& head) {
    if (!root) {
        return;
    }

    // Perform a Reverse Inorder because Inserting at the Start.
    convertBSTToLL(root->right, head);

    // Forming a Singly Linked List.

    if (head) {
        head->left = NULL;
    }

    root->right = head;
    head = root;

    convertBSTToLL(root->left, head);
}

void convertLLToMinHeap(Node*& root, Node*& head) {
    if (!head) {
        return;
    }

    root = head;
    head = head->right;

    // ! Setting these NULLs is v important to get the correct tree. Otherwise
    // Memory implementations would be all messed up.

    root->right = NULL;

    // Currently using a Queue to perform the Level Order Traversal, see how it may be done without.
    queue<Node*> q;
    q.push(root);

    while (head) {
        Node* parent = q.front(); q.pop();

        Node* leftChild = head;
        head = head->right;
        leftChild->right = NULL;
        q.push(leftChild);
        parent->left = leftChild;

        if (head) {
            Node* rightChild = head;
            head = head->right;
            parent->right = rightChild;
            rightChild->right = NULL;
            q.push(rightChild);
        }
    }
}

void convertBST(Node*& root) {
    Node* head = NULL;
    convertBSTToLL(root, head);

    root = NULL;
    convertLLToMinHeap(root, head);
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
     Node* root = createStaticBST();
     convertBST(root);
     printTree(root);
}