
/**
 * Find Diameter of Binary Tree.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BinaryNode{
public:
    BinaryNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
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

int heightBinaryTree(BinaryNode* root)
{
    if (!root)
        return -1;
    return 1 + max(heightBinaryTree(root->left), heightBinaryTree(root->right));
}

/**
 * Algo:
 * Diameter is maximum of left tree diameter,
 * right tree diameter, sum of left and right tree heights (
 * which is the maximum length path passing through 
 * the root)
 * Diameter is defined as the *number* of Nodes in the maximum length path.
 */
// int diameterBinaryTree(BinaryNode* root)
// {
//     if (!root)
//         return 0;

//     // if (!root->left && !root->right)
//     //     return 1;

//     return max(max(diameterBinaryTree(root->left), diameterBinaryTree(root->right)),
//                heightBinaryTree(root->left) + heightBinaryTree(root->right) + 3);
// }

/**
 * Optimized Algorithm.
 * Time Complexity: O(N).
 */
int diameterBinaryTree(BinaryNode* root, int& height)
{
    int hl=0, hr=0;

    if (!root)
    {
        height = 0;
        return 0;
    }

    int d1 = diameterBinaryTree(root->left, hl);
    int d2 = diameterBinaryTree(root->right, hr);

    height = max(hl, hr) + 1;
    
    return max(max(d1, d2), hl+hr+1);
}
int main()
{
    BinaryNode* root = new BinaryNode(1);
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->left->left = new BinaryNode(4);
    root->left->right = new BinaryNode(5);
//     vector<int> nodes = {1, 2, 3, 4, 5, -1, -1, 2};
//     BinaryNode* root = constructBinaryTree(nodes);
    int height = 0;
    cout << diameterBinaryTree(root, height);   
}