#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// beg is the first element, end is the last element.
void quickSortUtil(vector<int>& v, vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg >= end)
        return; 

    int pivot = *next(beg, distance(beg, end)/2);

    auto it1 = partition(beg, end+1, [pivot](const int& x) {return x <= pivot;});

    quickSortUtil(v, beg, it1-1);
    quickSortUtil(v, it1+1, end);
}

int main() {
    vector<int> v{7, 1, 3};
    quickSortUtil(v, v.begin(), v.end()-1);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}