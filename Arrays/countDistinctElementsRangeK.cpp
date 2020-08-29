// Find count of distinct elements in every subarry of size k.
// https://www.techiedelight.com/count-distinct-elements-every-sub-array-size-k-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countDistinct(vector<int>& v, int k) {
    unordered_map<int, int> m;

    k = min((int) v.size(), k);

    for (int i=0; i<k; i++) {
        m[v[i]]++;
    }
    
    cout << m.size() << " ";
    int slow = 0, fast=k;

    while (fast < v.size()) {
        m[v[slow]]--;
        if (m[v[slow]] == 0) {
            m.erase(v[slow]);
        }

        m[v[fast]]++;
        cout << m.size() << " ";
        slow++;
        fast++;
    }
    cout << endl;
}

int main() {
    vector<int> v{2, 1, 2 ,3 , 4, 1, 4, 4};
    countDistinct(v, 5);
}