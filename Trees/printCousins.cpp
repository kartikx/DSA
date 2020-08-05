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

BinaryNode* findNode(BinaryNode* root, BinaryNode* p, int l, int val, int& level)
{
    if (!root)
        return NULL;
    
    if (root->val == val)
    {
        if (!p) {
            return NULL;
        }

        level = l;
        return p;
    }

    BinaryNode* p1 = findNode(root->left, root, l+1, val, level);
    BinaryNode* p2 = findNode(root->right, root, l+1, val, level);

    return p1 ? p1: p2;
}

void printCousinsUtil(BinaryNode* root, BinaryNode* currParent,int currLevel, BinaryNode* parent, int level)
{
    if (!root)
        return;
    
    if (currLevel == level && currParent != parent)
    {
        cout << root->val << " ";

        // You wouldn't go deeper, if you've reached the level.
        return;
    }

    printCousinsUtil(root->left, root, currLevel+1, parent, level);
    printCousinsUtil(root->right, root, currLevel+1, parent, level);
}

void printCousins(BinaryNode* root, int val)
{
    if (!root)
        return;
    
    BinaryNode* parent = new BinaryNode(0);
    int level = -1;
    parent = findNode(root, NULL,0, val, level);

    printCousinsUtil(root, NULL, 0, parent, level);
}

int main()
{
    vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    BinaryNode* root = constructBinaryTree(nodes1);
    printCousins(root, 4);
} 
