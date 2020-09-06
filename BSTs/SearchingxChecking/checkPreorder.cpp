// Given an array of integers, check
// whether it can represent a BST's Preorder Traversal.
// Expected Time Complexity O(N).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * One thing to take care of is that the same preorder can represent
 * a valid BST as well as an invalid one.
 * You may NOT pick up a non-valid BST, get it's preorder and then
 * claim that the preorder is invalid. It may be possible
 * that for the same preorder a different "looking" BST is possible.
 * 
 * Approach: The main idea is that in a Preorder, I traverse Roots first.
 * So I keep track of the Roots I have visited. I also keep track of the root
 * whose right subtree I'm currently in (initially you're in the Right Subtree of
 * an imaginary INT_MIN root). Basically you should never encounter a node smaller
 * than this root.
 * When you encounter a node which is bigger than the last visited node, you'll pop
 * out elements, because this means that you have reached the right subtree of some
 * intermediate node. Hence as you pop out, also change the Root Value. Now the
 * next appearing values can either be in the right subtree of this new node, or they
 * can be in the right subtree of some ancestor (in which case, it would pop out 
 * more nodes.)
 */

bool canRepresentBST(vector<int> preOrder) {
    if (preOrder.empty()) {
        return false;
    }

    stack<int> s;
    int root = INT_MIN;

    for (int i=0; i<preOrder.size(); ++i) {
        if (preOrder[i] <= root) {
            return false;
        }

        while (!s.empty() && s.top() < preOrder[i]) {
            root = s.top();
            s.pop();
        }

        s.push(preOrder[i]);
    }

    return true;
}

void canRepresentBSTUtil(vector<int>& v, int& index, int min, int max) {

    if (index >= v.size()) {
        return;
    }

    int curr = v[index];

    if (curr > min && curr < max) {
        index++;
        canRepresentBSTUtil(v, index, min, curr);
        canRepresentBSTUtil(v, index, curr, max);
    }

    return;
}

bool canRepresentBST2(vector<int>& v) {
    int index = 0;
    canRepresentBSTUtil(v, index, INT_MIN, INT_MAX);
    return index == v.size() ; 
}

int main() {
    vector<int> v{10, 5, 1, 3, 6, 2};
    cout << canRepresentBST2(v) << endl;
}