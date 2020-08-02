/**
 * Iterative Inorder Traversal.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BinaryNode{
public:
    BinaryNode(int val)
    {
        this->val = val;
    }
    BinaryNode* left;
    BinaryNode* right;
    int val;
};

// Level order traversal.
void printBinaryTree(BinaryNode* root)
{
    if (!root)
        return;
    queue<BinaryNode*> q;
    q.push(root);
    while(!q.empty())
    {   
        int q_size = q.size();
        for (int i=0;i<q_size;i++)
        {
            BinaryNode* currNode = q.front();
            q.pop();
            if (currNode)
            {
                cout << currNode->val << " ";
                // pushing in nulls as well (if exist)
                q.push(currNode->left);
                q.push(currNode->right);
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}

BinaryNode* constructBinaryTreeUtil(vector<int>& nodes, int index)
{
    if (index >= nodes.size() || nodes[index] == -1)
        return NULL;
    BinaryNode* newNode = new BinaryNode(nodes[index]);
    newNode->left = constructBinaryTreeUtil(nodes, index*2 + 1);
    newNode->right = constructBinaryTreeUtil(nodes, index*2 + 2);
    return newNode;
}

// Pass into this perfect binary tree vector. -1 for null.
BinaryNode* constructBinaryTree(vector<int>& nodes)
{
    BinaryNode* root = constructBinaryTreeUtil(nodes, 0);
    return root;
}

void inOrderIterative(BinaryNode* root)
{
    if (!root)
        return;
    
    stack<BinaryNode*> s;
    BinaryNode* curr = root;

    /**
     * The first condition checks if traversing deeper is possible.
     * If I have a node, then go left.
     * In the else condition, I'm backtracking.
     * If you've reached a NULL, backtrack.
     * If you can't backtrack, nor have a current node. Quit.
     */
    while(!s.empty() || curr != NULL)
    {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }

    }
}

/*
        1
    2       3
6     7    -   8
*/

int main()
{
    vector<int> nodes1 = {1, 2, 3, 6, 7, -1, 8};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    inOrderIterative(root1);
} 
