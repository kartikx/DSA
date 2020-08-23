#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Since the Heap is being given in vector form,
 * there can't be any missing nodes in between.
 * (If you try to skip a left node before a right,
 * then it would just get interpreted as a left).
 * So all you need to check is the values.
 */
bool isMinHeap(vector<int>& v, int index) {
    // If leaf return true. (Only need to check left index for this, as can't have right without left.)
    if (2*index + 1 >= v.size())
        return true;
    
    // At this point, Ik I have left child.
    bool left = (v[index] <= v[2*index+1]) && isMinHeap(v, 2*index+1);

    // This node might not have a right child. Which means it is the last internal node.
    bool right = (2*index + 2 == v.size()) || (v[index] <= v[2*index+2] && isMinHeap(v, 2*index+2));

    return left && right;
}

bool isMinHeapIterative(vector<int>& v) {
    // Iterate only over the Internal Nodes. All internal nodes have a left child.
    // But the last one might not have a right child.
    for (int i=0; i <= v.size()/2 - 1; ++i) {
        if (v[i] > v[2*i+1] || (2*i + 2 < v.size() && v[i] > v[2*i+2]))
            return false;
    }
    return true;
}

int main() {
    vector<int> v{2, 1, 7, 2, 8};
    cout << isMinHeapIterative(v) << endl;
    make_heap(v.begin(), v.end(), greater<int>());
    cout << isMinHeapIterative(v) << endl;
}