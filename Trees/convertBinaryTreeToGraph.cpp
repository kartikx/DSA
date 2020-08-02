/**
 * Some standard methods for Binary Tree.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int>* Graph;

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

/** Naive Implementation, wastes a lot of space because
 * using the value as the Node Value.
 */

/*
    I'm curently at root. Since I don't know the size beforehand, I'm going to store my grapoh
    as a vector<vector<int>>. Initially empty. vector<vector<int>>().
    void foo(v<v<int>>, int index) {
    count = index;
    for (child in root->children) {
        if (child) {
            // g[idMap[root->val]].push_back(idMap[child->val]);
            g[index].push_back(++count);
            g.push_back(vector<int>()); // this is for the child.
            g[index+1].push_back(
        }
    }
*/


/* This numbers Depth First.
 * Count represents the id you should assign to a child.
 * Index represents the id of the node you are at.
 */
/*
void convertToGraphUtil(BinaryNode* root, vector<vector<int>>& g,int index, int& count)
{
    if (!root) {
        return;
    }

    //count is index+1.
    if (root->left) {
        count++;
        g[index].push_back(count);
        g.push_back(vector<int>());
        g[count].push_back(index);
        convertToGraphUtil(root->left, g, count, count);
    }

    if (root->right) {
        count++;
        g[index].push_back(count);
        g.push_back(vector<int>());
        g[count].push_back(index);
        convertToGraphUtil(root->right, g, count, count);
    }


}
*/

// This numbers level order.
// void convertToGraphUtil(BinaryNode* root, vector<vector<int>>& g, int index)
// {
//     if (!root) {
//         return;
//     }
//     queue<pair<BinaryNode*, int>> q;
//     q.push(make_pair(root, index));
//     int counter = 1;

//     while(!q.empty())
//     {   
//         int q_size = q.size();
//         for (int i=0; i<q_size; i++){
//             auto pair = q.front();
//             BinaryNode* currNode = pair.first;
//             int currIndex = pair.second;
//             q.pop();
//             if (currNode->left) {
//                 g[currIndex].push_back(counter);
//                 g.push_back(vector<int>());
//                 g[counter].push_back(currIndex);
//                 q.push(make_pair(currNode->left, counter));
//                 counter++;
//             }
            
//             if (currNode->right) {
//                 g[currIndex].push_back(counter);
//                 g.push_back(vector<int>());
//                 g[counter].push_back(currIndex);
//                 q.push(make_pair(currNode->right, counter));
//                 counter++;
//             }
//         }
//     }
// }



/**
 * This function is unaware of its number of nodes.
 * It takes a tree, and numbers it's nodes independent of the node values, based
 * on the Inorder traversal.
 */
void convertToGraph(BinaryNode* root)
{
    vector<vector<int>> g;
    int count = 0;
    g.push_back(vector<int>());
    convertToGraphUtil(root, g, 0);

    for (int i=0;i<g.size();i++)
    {   
        cout << i << ": "; 
        for (int u : g[i])
        {
            cout << u << ", ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nodes = {1, 2, 3, 6, 7, -1, 8};
    int tree_size = 9;
    BinaryNode* root = constructBinaryTree(nodes);  
    convertToGraph(root);
}