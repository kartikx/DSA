#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

/**
 * View this problem as a generalization of the standard merge
 * problem. The basic idea is to iterate from left to right across
 * all arrays, and increment the counter of the array whose current Index
 * is the smallest one.
 * Using K different counters can become very clumsy, moreover every time
 * we'll have to find the smallest element in O(K) time.
 * Instead use a min-heap, which can give the smallest element in O(1) time,
 * and moreoever, addition takes only O(logK) time.
 */
vector<int> mergeKSortedList(vector<vector<int>> V) {
    // Stores pairs of (val, (list num, index in list))
    vector<pair<int, pair<int, int>>> v_heap;
    unsigned int totalSize = 0;
    for (int i=0; i<V.size(); i++) {
        v_heap.push_back({V[i][0], {i, 0}});
        totalSize += V[i].size();
    }

    // Pushing all elements back and then using make_heap is faster.
    // Both asymptotically, and through clock() measurements as well.
    make_heap(v_heap.begin(), v_heap.end(), greater<pair<int, pair<int, int>>>());

    vector<int> output(totalSize, 0);

    for (int i=0; i<totalSize; ++i) {
        auto topNode = v_heap[0];
        int minVal = topNode.first;
        int listNum = topNode.second.first;
        int listIndex = topNode.second.second;

        output[i] = minVal;
        pop_heap(v_heap.begin(), v_heap.end(), greater<pair<int, pair<int, int>>>());
        v_heap.pop_back();

        if (listIndex < V[listNum].size() - 1) {
            v_heap.push_back({V[listNum][listIndex+1], {listNum, listIndex+1}});
            push_heap(v_heap.begin(), v_heap.end(), greater<pair<int, pair<int, int>>>());
        }
    }
    return output;
}

int main() {
    vector<int> v1{3, 4, 6};
    vector<int> v2{2, 3};
    vector<int> v3{1, 7};

    vector<vector<int>> V(3);
    V[0] = v1;
    V[1] = v2;
    V[2] = v3;

    vector<int> ans = mergeKSortedList(V);

    for (auto x : ans) {
        cout << x << " " ;
    }

    cout << endl;
}