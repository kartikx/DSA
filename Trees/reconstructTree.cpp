/**
 * Reconstruct a Tree given an AHU encoding.
 * Tree not necessarily binary.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 6
#define forn(i, start, end) for(int i=start;i<end;i++)

class TreeNode{
public:
    TreeNode(int id, int parentId)
    {
        this->id = id;
        this->parentId = parentId;
    }

    int id;
    int parentId;
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

/**
 * Algorithm: First traverse from L to R, the
 * first bracket is always a (, so find the matching ) for this.
 * No need for stack basic count se ho jaega. Once you have this matching
 * bracket, the part between the two represents the left node (not necessarily waise),
 * and the remaining part represents the right node. So continue.
 */
int id = 0;
TreeNode* reconstructTree(string code)
{
    if (code.empty())
        return NULL;

    int start = 0, end;
    // first remove the brackets around the root.
    code = code.substr(1, code.size()-2);

    // now find the matching subparts within the code.
    TreeNode* node = new TreeNode(id++, 0);

    if (code.empty())
        return node;

    vector<string> codes;

    while (start < code.size())
    {
        int countL = 0, countR = 0;
        end = 0;
        for (int i = start ; i<code.size() ; i++)
        {
            if (code[i] == '(')
                countL++;
            else
            {
                countR++;
            }
            if (countL == countR)
            {
                end = i;
                break;
            }
        }
        if (start < end)
        {
            string tempCode = code.substr(start, end - start + 1);
            codes.push_back(tempCode);
            start = end + 1;
        }
    }

    for (auto tempCode : codes)
    {
        node->children.push_back(reconstructTree(tempCode));
    }

    return node;
}

int main()
{
    TreeNode* root = reconstructTree("((()()())(()()))");
    printTree(root);
}
