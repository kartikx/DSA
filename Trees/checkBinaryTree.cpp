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

void getArrayRepr(BinaryNode* root, int index, vector<int>& t)
{
    if (!root)
        return;
    
    if (index < t.size()) {
        t[index] = root->val;
    }

    if (2*index + 2 > t.size())
    {
        t.resize(t.size() * 2);
    }

    getArrayRepr(root->left, 2*index+1, t);
    getArrayRepr(root->right, 2*index+2, t);    
}

bool isCompleteBinaryTree(BinaryNode* root)
{
    if (!root)
    {
        return false;
    }

    vector<int> tree_repr(1, 0);
    getArrayRepr(root, 0, tree_repr);

    tree_repr.shrink_to_fit();
    bool found0 = false;

    for (auto x : tree_repr)
    {
        if (x != 0 && found0)
            return false;
        if (x == 0 && !found0)
            found0 = true;
    }

    return true;
}

/**
 * One possible logic could be to perform Level Order Traversal
 * and check that a Node with a Non-Null child does not appear after
 * a Node with one (or both) child as Null. O(N) time and O(N) Space.
 * 
 * Another approach could be to write down the vectorized Tree
 * representation, as demonstrated.
 * 
 * The Final Optimized Approach, doesn't require Auxiliary Space.
 * It uses the Observation that in a Complete Binary Tree, Index of Children
 * of every Node (2i and 2i+1) is less than N.
 */

// Why this works is that if you are to remove a Node from in between, then
// the number of total nodes will decrease, however the indices in the upper layer
// hasn't changed. Hence, the right most index of the lower layer as computed will come
// out to be one larger than the number of nodes.

bool isCompleteBinaryTreeOpt(BinaryNode* root, int i, int n)
{
    if (!root)
        return true;
    
    if ((root->left && 2*i + 1 >= n) || (!isCompleteBinaryTreeOpt(root->left, 2*i+1, n))) 
        return false;

    if ((root->right && 2*i + 2 >= n) || (!isCompleteBinaryTreeOpt(root->right, 2*i+2, n))) 
        return false;    

    return true;
}



int main()
{
    // vector<int> nodes1 = {1, 2, 3, -1, 4, 5, 6, -1, -1,-1, -1,  7, 8, -1, -1};
    vector<int> nodes1 = {1, 2, 3, 4, 5, 6, 7};
    BinaryNode* root = constructBinaryTree(nodes1);

    cout << isCompleteBinaryTreeOpt(root, 0, 7);
}
