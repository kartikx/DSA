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

void printLeftView(BinaryNode* root)
{
    if (!root)
        return;

    queue<BinaryNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int q_size = q.size();
        bool printed = false;

        for (int i=0 ; i<q_size ; i++)
        {
            BinaryNode* curr = q.front();
            q.pop();

            if (!printed) {
                printed = true;
                cout << curr->val << " ";
            }

            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }

    return ;
}

void printLeftViewUtilNaive(BinaryNode* root, int level, vector<bool>& printed)
{
    if (!root)
    {
        return;
    }
    if (!printed.at(level))
    {
        cout << root->val << " ";
        printed.at(level) = true;
    }

    printed.push_back(false);

    printLeftViewUtilNaive(root->left, level+1, printed);
    printLeftViewUtilNaive(root->right, level+1, printed);
}

void printLeftViewUtil(BinaryNode* root, int level, int& maxLevel)
{
    if (!root)
    {
        return;
    }
    if (level > maxLevel)
    {
        cout << root->val << " ";
        maxLevel = level;
    }

    printLeftViewUtil(root->left, level+1, maxLevel);
    printLeftViewUtil(root->right, level+1, maxLevel);
}

/**
 * One Recursive Approach, as in printLeftViewUtilNaive 
 * could be to have a "printed" which stores
 * whether a node in that level has been printed already.
 * That solution would be O(N) time and O(N) space.
 * Instead we could solve in O(1) space, by maintaining the max Level
 * visited so far. Print the current Node only if level > maxLevel, 
 * and update maxLevel.
 */

void printLeftViewRecursive(BinaryNode* root)
{
    if (!root)
        return ;
    
    // vector<bool> printed(1, false);
    // printLeftViewUtil(root, 0, printed);

    int maxLevel = 0;
    printLeftViewUtil(root, 1, maxLevel);
}

/*
            1
        2       3
    4     5   6    7
*/

int main()
{
    vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    printLeftViewRecursive(root1);
} 
