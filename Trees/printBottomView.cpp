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

void printBottomViewUtil(BinaryNode* root, int horLevel, int level, unordered_map<int, pair<int, int>>& M, int& minHLevel, int& maxHLevel)
{
    if (!root)
        return;

    if (horLevel < minHLevel)
        minHLevel = horLevel;
    
    if (horLevel > maxHLevel)
        maxHLevel = horLevel;

    // Not necessary to check whether M[horLevel] exists, if it doesn't
    // M[horLevel].first and M[horLevel].second will return 0. since level
    // passed is >= 1 always, it will work.
    if (M[horLevel].first < level)
    {
        // Don't use Insert here, as it doesn't allow repeated elements.
        M[horLevel] = make_pair(level, root->val);
    }

    printBottomViewUtil(root->left, horLevel-1, level+1,  M, minHLevel, maxHLevel);
    printBottomViewUtil(root->right, horLevel+1, level+1,  M, minHLevel, maxHLevel);
    return;
}

void printBottomView(BinaryNode* root)
{
    if (!root)
        return;
    
    // Map of horLevel -> (vertical Level, nodeValue)
    // You could use a Map to get O(NLogN), using Unordered will give O(N)
    unordered_map<int, pair<int, int>> M;

    int minHLevel = 0, maxHLevel = 0;
    printBottomViewUtil(root, 0, 1, M, minHLevel, maxHLevel);

    for (int i=minHLevel ; i <= maxHLevel ; i++)
    {
        auto it = M.find(i);

        if (it != M.end())
            cout << it->second.second;
    }
}

int main()
{
    vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    printBottomView(root1);
} 
