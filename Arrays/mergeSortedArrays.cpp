#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeVec(vector<int>& v1, vector<int>& v2) {
    vector<int> v(v1.size() + v2.size(), 0);

    int i=0, j=0, c=0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            v[c++] = v1[i++];
        }
        else {
            v[c++] = v2[j++];
        }
    }

    while (i < v1.size()) {
        v[c++] = v1[i++];
    }
    
    while (j < v2.size()) {
        v[c++] = v2[j++];
    }

    return v;
}

void mergeVecInPlace(vector<int>& v1, vector<int>& v2) {
    /**
     * The main issue with sorting in place is that you'll end
     * up overwriting the container you're iterating over.
     * To avoid this, in the container that we're adding to,
     * we check elements at the beginning, but add elements to the end.
     * That is, instead of inserting the smallest element, we're appending
     * the largest element every time.
     */
    int i=v1.size()-1, j=v2.size()-1, k=v1.size()+v2.size()-1;

    v1.resize(v1.size()+v2.size(), 0);

    while (i>= 0 && j >= 0) {
        /*
         * Eventually, this will overwrite elements. However I can be sure
         * that that happens only when the element being overwritten, has already
         * been assigned somewhere ahead in the array, because:
         * 1. Overwrite happens only when the right v2.size() portion has been filled.
         * 2. This portion can't be filled entirely with v2, because then the loop would
         * have stopped.
        */
        if (v1[i] < v2[j]) {
            v1[k--] = v2[j--];
        }
        else {
            v1[k--] = v1[i--];
        }
    }

    // If there're elements left in V2, then that means they're the smallest of the lot.
    while (j >= 0) {
        v1[k--] = v2[j--];
    }
}

int main() {
    vector<int> v1{10, 30, 50, 60};
    vector<int> v2{20, 25, 55, 80};

    mergeVecInPlace(v1, v2);

    for (auto x : v1) {
        cout << x << " ";
    }
    cout << endl;
    // std::merge?
}