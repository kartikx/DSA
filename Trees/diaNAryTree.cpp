#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    TreeNode(int id)
    {
        this->id = id;
    }

    int id;
    vector<TreeNode*> children;
};

/**
 * BFS on Tree.
 */
void printTree(TreeNode* root)
{
    if (!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {   
        int q_size = q.size();
        for (int i=0;i<q_size;i++)
        {
            TreeNode* currNode = q.front();
            q.pop();
            cout << currNode->id << " ";
            for (auto x : currNode->children)
            {
                q.push(x);
            }
        }
        cout << endl;
    }
}

int heightNAryTree(TreeNode* root)
{
    if (!root)
    {
        return -1;
    }

    int maxHeight = -1;
    for (auto x : root->children)
    {
        maxHeight = max(maxHeight, heightNAryTree(x));
    }
    return maxHeight + 1;
}

/**
 * Similar logic used in Binary Diameter.
 * Since there are many children, you just need
 * to consider the maximum values and return those.
 */

int diameterNAryTree(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    int maxDia = -1;

    int max1 = -1, max2 = -1;
    for (auto child : root->children)
    {
        int height = heightNAryTree(child);
        if (height > max1)
        {   
            max2 = max1;
            max1 = height;
        }
        else if (height > max2)
        {
            max2 = height;
        }
    }

    for (auto child : root->children)
    {
        maxDia = max(maxDia, diameterNAryTree(child));
    }

    return max(maxDia, max1+max2+3);
}

int main()
{
    TreeNode *root = new TreeNode('A'); 
    (root->children).push_back(new TreeNode('B')); 
    (root->children).push_back(new TreeNode('F')); 
    (root->children).push_back(new TreeNode('D')); 
    (root->children).push_back(new TreeNode('E')); 
    (root->children[0]->children).push_back(new TreeNode('K')); 
    (root->children[0]->children).push_back(new TreeNode('J')); 
    (root->children[2]->children).push_back(new TreeNode('G')); 
    (root->children[3]->children).push_back(new TreeNode('C')); 
    (root->children[3]->children).push_back(new TreeNode('H')); 
    (root->children[3]->children).push_back(new TreeNode('I')); 
    (root->children[0]->children[0]->children).push_back(new TreeNode('N')); 
    (root->children[0]->children[0]->children).push_back(new TreeNode('M')); 
    (root->children[3]->children[2]->children).push_back(new TreeNode('L')); 
  
    cout << diameterNAryTree(root);
}