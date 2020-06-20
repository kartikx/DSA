/**
 * Implementation to find all possible Topological Sorts
 * given a Graph. Using modification of Kahn's algorithm
 * for this.
 */

#include <bits/stdc++.h>
#include <iostream>
# define print(str) cout << str << endl;
# define forn(i, start, end) for(int i=start;i<end;i++) 
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

void printGraph(vector<int> graph[], int v)
{
    forn(i,0,v)
    {
        for(auto x : graph[i])
            cout << x << " " ;
        cout << endl;
    }
}

/**
 * Try working out Kahn's algo. using a test Graph, you'll
 * notice that the different topo sorts arise because every
 * time you pick an element from the Q, you have an option 
 * which one to pick.
 * Intuitively this can be thought of as decision branching,
 * Using stack nature of recursion seems like the best course of action.
 */
void kahnUtil(vector<int> graph[], queue<int>& toVisit, vector<int>& indegree, vector<int> &result)
{
    int size = toVisit.size();

    forn(i, 0, size){
        /**
         * Temps are needed to not affect other options
         * that you may have chosen (you'll eventually choose these).
         */
        queue<int> tempQueue(toVisit);
        vector<int> tempInDegree(indegree);

        int val = tempQueue.front();
        tempQueue.pop();
        toVisit.pop();
        // This is needed, because on next iteration, you want to consider a 
        // different value, however that value must have this value in its queue.
        toVisit.push(val);
        result.push_back(val);
        for (int x : graph[val]){
            tempInDegree[x]--;
            if (tempInDegree[x] == 0)
                tempQueue.push(x);
        }

        kahnUtil(graph, tempQueue, tempInDegree, result);

        if(result.size() == indegree.size())
        {
            for (auto x : result)
                cout << x << " ";
            cout << endl;
        }
        result.pop_back();
    }
}

/**
 * This method calls the Util method, after
 * initializing the Queue with the initial set
 * of vertices with 0 in-degree.
 */
void kahntoposort(vector<int> graph[], int size)
{
    // initialize
    vector<int> indegree(size,0);
    vector<int> result;
    forn(i,0,size)      //O(V+E)
    {
        for(auto it = graph[i].cbegin(); it!=graph[i].cend();it++)
        {
            indegree[*it]++;
        }
    }
    queue<int> toVisit;
    forn(i,0,size)  // O(V)
    {
        if (indegree[i] == 0)
            toVisit.push(i);
    }
    kahnUtil(graph, toVisit, indegree, result);
}

int main()
{
    int v;
    cin >> v;
    vector<int> graph[v];

    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 0);
    addEdge(graph, 5, 2);

    kahntoposort(graph, v);
}
