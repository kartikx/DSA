/**
 * Clickbait: This isn't actually recursion.
 * This is actually worse time complexity than a Queue based approach.
 * Time Complexity is O(N*2), but O(1) space complexity.
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

bool printLevel(BinaryNode* root, int level)
{
    if (!root) {
        return false;
    }

    if (level == 1) {
        cout << root->val << " " ;
        return true;
    }

    bool b1 = printLevel(root->left, level-1);
    bool b2 = printLevel(root->right, level-1);

    // GOTCHA: If you replaced b1 and b2 with the actual expressions themselves,
    // then printLevel for right may never be called. OR Shorting.
    return b1 || b2 ;
}

void levelOrderTraversal(BinaryNode* root) {
    if (!root) {
        return ;
    }

    bool isLevel = printLevel(root, 1);
    int c = 2;
    while(isLevel) {
        isLevel = printLevel(root, c++);
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
    levelOrderTraversal(root1);
} 
