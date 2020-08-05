// https://www.techiedelight.com/print-nodes-binary-tree-specific-order/

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

void printTopDown(BinaryNode* root)
{
    if (!root)
        return;
    cout << root->val << " ";
    queue<BinaryNode*> q;
    q.push(root->left);
    q.push(root->right);

    // need to check whether curr exists.

    while(!q.empty())
    {
        BinaryNode* currL = q.front();
        q.pop();
        BinaryNode* currR = q.front();
        q.pop();
        if (!currL || !currR)
            break;        
        cout << currL->val << " ";
        cout << currR->val << " ";

        if (currL->left)
            q.push(currL->left);
        if (currR->right)
            q.push(currR->right);
        if (currL->right)
            q.push(currL->right);
        if (currR->left)
            q.push(currR->left);
    }
}

void printBottomUp(BinaryNode* root)
{
    if (!root)
        return;
    stack<int> vals;
    vals.push(root->val);
    queue<BinaryNode*> q;
    q.push(root->right);
    q.push(root->left);


    while(!q.empty())
    {
        BinaryNode* curr1 = q.front();
        q.pop();
        BinaryNode* curr2 = q.front();
        q.pop();
        if (!curr1 || !curr2)
            break;
        
        vals.push(curr1->val);
        vals.push(curr2->val);

        if (curr1->left)
            q.push(curr1->left);
        if (curr2->right)
            q.push(curr2->right);
        if (curr1->right)
            q.push(curr1->right);
        if (curr2->left)
            q.push(curr2->left);
    }

    while(!vals.empty())
    {
        int curr = vals.top();
        vals.pop();
        cout << curr << " ";
    }
}

int main()
{
    vector<int> nodes1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 
    26, 27, 28, 29, 30, 31};
    BinaryNode* root1 = constructBinaryTree(nodes1);
    printBottomUp(root1);
} 
