/**
 * Given roots of two Binary Trees,
 * check if they are identical.
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

bool checkIdenticalBinaryTrees(BinaryNode* root1, BinaryNode* root2)
{
    if (!root1 && !root2) {
        return true;
    }

    if (!root1 || !root2) {
        return false;
    }

    // root1 and root2'
    return (root1->val == root2->val) && checkIdenticalBinaryTrees(root1->right, root2->right) && checkIdenticalBinaryTrees(root1->left, root2->left);
}


/**
 * You could use a stack or a Queue.
 */
bool checkIdenticalBinaryTreesIterative(BinaryNode* root1, BinaryNode* root2)
{
    if (!root1 && !root2)
        return true;
    
    if (!root1 || !root2)
        return false;
    
    queue<pair<BinaryNode*, BinaryNode*>> q;
    q.push(make_pair(root1, root2));

    while(!q.empty())
    {
        auto currPair = q.front();
        q.pop();

        BinaryNode* x = currPair.first;
        BinaryNode* y = currPair.second;
        if (x->val != y->val){
            return false;
        }

        if (x->left && y->left) {
            q.push({x->left, y->left});
        }
        else if (x->left || y->left) {
            return false;
        }
        
        if (x->right && y->right) {
            q.push({x->right, y->right});
        }
        else if (x->right || y->right) {
            return false;
        }
    }
    return true;
}

/*
        1
    2       3
6     7    -   8
*/

int main()
{
    vector<int> nodes1 = {1, 2, 3, 6, 7, -1, 8};
    vector<int> nodes2 = {1, 2, 3, 6, 7, -1, 7};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    BinaryNode* root2 = constructBinaryTree(nodes2);

    if (checkIdenticalBinaryTreesIterative(root1, root2)){
        cout << "Identical" ;
    }
    else {
        cout << "Not identical" ;
    }
}