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

void checkCousinUtil(BinaryNode* root, int level, int node1, int node2, int& level1, int& level2, int& count)
{
    if (!root || (level1 != -1 && level2 != -1))
        return;

    /*
        If you find a Node, you shouldn't go deeper
        into the Tree.
    */
    if (root->val == node1)
    {
        level1 = level;
        return;
    }

    if (root->val == node2)
    {
        level2 = level;
        return;
    }

    checkCousinUtil(root->left, level+1, node1, node2, level1, level2, count);
    checkCousinUtil(root->right, level+1, node1, node2, level1, level2, count);

    /*
        You reach here, when you're done traversing the Left and Right Subtrees.
        If you're still searching for One of the Nodes, then you should increment count.
        Count stores the number of nodes in the path through the root between the Nodes.
        Count will not be incremented if you're traversing back up the Tree, when both
        Nodes have been found. Since that occurs regardless of being cousins.
    */
    // For siblings Count will be 0.
    if (level1 != -1 || level2 != -1)
    {
        if (level1 == -1 || level2 == -1)
        {
            count++;
        }
    }
}

bool checkCousin(BinaryNode* root, int node1, int node2)
{
    if (!root)
        return false;
    
    int level1 = -1, level2 = -1, count=0;
    checkCousinUtil(root, 1, node1, node2, level1, level2, count);

    return (level1 == level2) && (count > 0);
}

int main()
{
    vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    if (checkCousin(root1, 7, 8)) {
        cout << "Cousins" << endl;
    }
    else {
        cout << "Not Cousins" << endl;
    }
} 
