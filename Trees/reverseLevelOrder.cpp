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

void printReverseLevelOrder(BinaryNode* root)
{
    if (!root)
        return;
    
    queue<BinaryNode*> q;
    q.push(root);
    stack<int> vals;

    while(!q.empty())
    {
        BinaryNode* curr = q.front();
        q.pop();
        vals.push(curr->val);

        if (curr->right) {
            q.push(curr->right);
        }

        if (curr->left) {
            q.push(curr->left);
        }
    }

    while(!vals.empty())
    {
        int curr = vals.top();
        vals.pop();
        cout << curr << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nodes1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    printReverseLevelOrder(root1);
} 
