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

/*
For a sum Tree, the L and R subtrees should be sum trees.
To prevent repeated computations, return 2*root value from
the subtree being considered.
For a valid subtree, the sum of the subtree will be 2*rootValue
*/
int isSumTree(BinaryNode* root)
{
    if (!root)
        return 0;
    
    // leaf
    if (!root->left && !root->right)
        return root->val;

    
    int ls = isSumTree(root->left);
    int rs = isSumTree(root->right);

    if (root->val == (ls+rs))
        return 2*root->val;

    // May be used to check in the caller function.
    return INT_MIN;
}

int main()
{
    // vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    vector<int> nodes1 = {40, 5, 15, -1, 5, 8, 7};
    BinaryNode* root = constructBinaryTree(nodes1);

    int val = isSumTree(root);

    if (val < 0) 
        cout << "Not a Sum Tree" << endl;
    else {
        cout << "Sum Tree" << endl;
    }

}
