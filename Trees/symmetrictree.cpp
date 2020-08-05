/**
 * Given a Binary Tree,
 * check whether it's symmetric.
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

BinaryNode* constructBinaryTree(vector<int>& nodes)
{
    BinaryNode* root = constructBinaryTreeUtil(nodes, 0);
    return root;
}

bool symmetricTreeUtil(BinaryNode* root1, BinaryNode* root2)
{   
    if (!root1 && !root2)
        return true;
    
    if (!root1 || !root2)
        return false;
    
    bool bValue = (root1->val == root2->val);

    if (bValue)
    {
        bool b1 = symmetricTreeUtil(root1->left, root2->right);
        bool b2 = symmetricTreeUtil(root1->right, root2->left);
        return (b1 && b2);
    }

    return false;
}

bool symmetricTree(BinaryNode* root)
{
    if (!root)
        return false;

    // make the check for if one doesn't exist in Util
    return symmetricTreeUtil(root->left, root->right);
}

int main()
{
    vector<int> nodes = {1,2,2,3,4,4,3, -1, -1, -1, 5, 5, -1};
    BinaryNode* root = constructBinaryTree(nodes);
    if (symmetricTree(root))
    {
        cout << "Symmetric";
        return 0;
    }
    cout << "Not Symmetric";
}