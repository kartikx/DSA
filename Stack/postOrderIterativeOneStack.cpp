/**
 * Some standard methods for Binary Tree.
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

// Using one stack only.
void postOrderIterative(BinaryNode* root)
{
    if (!root)
        return;
    
    stack<BinaryNode*> s;
    BinaryNode* curr = root;

    while(!s.empty() || curr)
    {
        if (curr) {
            if (curr->right)
                s.push(curr->right);
            s.push(curr);
            curr = curr->left;
        }

        else {
            BinaryNode* parentNode = s.top();
            s.pop();
            if (parentNode->right && !s.empty() && s.top() == parentNode->right) {
                curr = parentNode->right;
                s.pop();
                s.push(parentNode);
            }
            else {
                cout << parentNode->val << " " ;
                curr = NULL;
            }
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
    postOrderIterative(root1);
} 