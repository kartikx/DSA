/**
 * Find the LCA in a Binary Tree.
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

/**
 * This recursive call stops when you find any Node.
 * If you're guarranteed that keys exist, then if you find one of the keys,
 * and can't find the other key in the other parts of the tree, then you
 * can be sure that the found key is the LCA. However, if you're not
 * guaranteed then you should check later whether key2 is reachable
 * from where you'd stopped.
 */
Node* LCAUtil(Node* root, int key1, int key2, bool& v1, bool& v2) {
    if (!root) {
        return NULL;
    }

    if (root->val == key1) {
        v1 = true;
        return root;
    }

    if (root->val == key2) {
        v2 = true;
        return root;
    }

    Node* leftLCA = LCAUtil(root->left, key1, key2, v1, v2);
    Node* rightLCA = LCAUtil(root->right, key1, key2, v1, v2);

    if (leftLCA && rightLCA)
        return root;
    
    return (leftLCA ? leftLCA : rightLCA);
}

bool find(Node* root, int key) {
    if (!root) {
        return false;
    }

    return (root->val == key) || find(root->left, key) || find(root->right, key);
}

/**
 * Explanation:
 * The main idea behind searching for LCA in a Binary Tree is that you have to check both
 * subtrees in any case.
 * Now the LCA is either a node for which the two values appear on opposite sides. There
 * will be only one such node.
 * Or the LCA may be one of the nodes you're searching for, as the other value may appear
 * in its subtree.
 * So the main Idea is to start traversing from the root, if at any point your val becomes
 * equal to one of the keys, your root will become the LCA.
 * Else you should traverse in root->left as well as root->right.
 * If both root->left and root->right return something, then root is the answer. Else
 * return whichever one returned something (because some higher up may become LCA or only the
 * left or right may be the LCA).
 * Note that when you come across a root which is one of the keys you immediately return, assuming
 * that the other key will appear below it. If this assumption is false, then the other key will 
 * appear in the other subtree of some upper node, and it will become the answer.
 * This is the basis for the extension of the solution to the key may not exist case.
 */

Node* LCA(Node* root, int key1, int key2) {
    bool v1=false, v2=false;
    Node* ans =  LCAUtil(root, key1, key2, v1, v2);

    if ((v1 && v2) || (v1 && find(ans, key2)) || (v2 && find(ans, key1))) {
        return ans;
    }

    return NULL;
}

Node* createBT() {
    Node* root = new Node(11);
    root->left = new Node(12);
    root->left->left = new Node(18);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(2);
    root->right = new Node(10);
    root->right->left = new Node(4);
    root->right->right = new Node(13);
    return root;
}

int main() {
    Node* root = createBT();

    cout << LCA(root, 18, 14)->val << endl;
}