// Given a preorder array, check whether each node of the BST
// contains only one child. Expected Time O(N).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The main idea is that generally for preorder arrays,
 * for every index you first have a stretch of smaller
 * values, followed by a stretch of larger values.
 * In One Child scenarios, there should just be one big stretch.
 * Instead of iterating over the stretch to confirm, you could
 * check for every node for just the next and last elements.
 * This check is sufficient because in between these 2 elements,
 * you can't have an element which is on different side (of the number line),
 * because first I should have all small, and then all big.
 */
bool containsOneChild(vector<int>& preorder) {
    if (preorder.empty()) {
        return true;
    }

    int diffNext = 0, diffLast = 0;
    for (int i=0; i<preorder.size()-1; i++) {
        diffNext = preorder[i] - preorder[i+1];
        diffLast = preorder[i] - preorder.back();
        if (diffNext * diffLast < 0) {
            return false;
        }
    }

    return true;
}

/**
 * Alternative Approach:
 * For each node if you're aware of the min and max values
 * to its right, then the node can't lie in between those two values.
 * So start from the right-3rd element, and iterate leftwards.
 */
bool containsOneChildAlt(vector<int>& preorder) {
    if (preorder.empty()) {
        return true;
    }

    // Set up min and max values.
    int min=INT_MAX, max=INT_MIN;

    if (preorder.back() > preorder[preorder.size()-2]) {
        max = preorder.back();
        min = preorder[preorder.size()-2];
    }

    else {
        min = preorder.back();
        max = preorder[preorder.size()-2];    
    }

    for (int i=preorder.size()-3; i>=0; --i) {
        if (preorder[i] < min) {
            min = preorder[i];
        }

        else  if (preorder[i] > max) {
            max = preorder[i];
        }

        else {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> preorder = {20, 10, 11, 13, 12};
    cout << containsOneChildAlt(preorder) << endl;
}