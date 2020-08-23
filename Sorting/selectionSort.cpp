/*
Basic Idea : Pluck the smallest element to the right
of the index you're trying to fix. Swap the current element
with this element.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& v) {
    // Swapping every time I find a smaller element, to make sorting stable.
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < v[i]) {
                swap(v[i], v[j]);
            }
        }
    }
}

int main() {
    vector<int> v{7, 4, 3, 2, 1, 5};
    selectionSort(v);

    for_each(v.begin(), v.end(), [](int& x) {cout << x << " ";});
    cout << endl;
}