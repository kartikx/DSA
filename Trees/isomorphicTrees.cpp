#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 6
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;
typedef list<pair<int,int>>* wG;
typedef pair<int, pair<int, int>> T;

// Unweighted graphs generally Undirected
void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}

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

vector<int> findCenter(G graph, int size)
{
    // at max 2 centers
    vector<int> res(2, -1);
    vector<int> degrees(size);
    vector<int> leaves;

    forn (i, 0, size)
    {
        degrees[i] =  graph[i].size();
    }

    forn (i, 0, size)
    {
        if (degrees[i] == 1)
            leaves.push_back(i);
    }

    int count = leaves.size();

    while (count < size)
    {
        vector<int> new_leaves;
        for (auto leaf : leaves)
        {
            for (auto x : graph[leaf])
            {
                degrees[x]--;
                if (degrees[x] == 1)
                    new_leaves.push_back(x);
            }
        }
        leaves = new_leaves;
        count += new_leaves.size();
    }

    forn (i, 0, leaves.size())
        res[i] = leaves[i];
    return res;
}

TreeNode* rootTree(G graph, int u, int parent)
{
    TreeNode* node = new TreeNode(u, parent);
    for (auto x : graph[u])
    {
        if (parent == x)
            continue;
        node->children.push_back(rootTree(graph, x, u));
    }
    return node;
}

// AHU Encoding of the Tree.
string encodeTree(TreeNode* root)
{
    if (!root)
        return "";
    
    vector<string> codeList;
    for (auto x : root->children)
    {
        codeList.push_back(encodeTree(x));
    }
    sort(codeList.begin(), codeList.end());

    string code = "";
    for (auto x : codeList)
        code += x;
    return "(" + code + ")" ;
}

int main()
{
    list<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    
    // Similarly construct the other graph.

    /**
     * Algorithm:
     * First find the centers of the two graphs,
     * and root them about their centers.
     * Next compare the AHU Coding of the rooted trees.
     * Since you may have two centers, you should compare
     * for both.
     */
    
}
