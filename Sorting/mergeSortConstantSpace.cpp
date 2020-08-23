#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ! std merge!.
/**
 * The main issue is that you'll overwrite the same array you're traversing.
 * To avoid that, we need some way of getting the original value, as well as
 * the correct sorted value for every position in the array.
 * We do this by placing a correct number as: orgValue + newValue * (maxValue+1).
 * This allows us to get the current value as %(maxValue+1) and orgValue (for
 * comparison purpose) as /(maxValue+1).
 * We're using maxValue+1, because originally, when you haven't altered anyone,
 * you'd want the currentValue to return the actual value.
 * Also maxVal+1, and not just maxVal, to avoid issues with the actual maxVal number.
 */
void mergeVec(vector<int>& v, int l, int m, int r, int maxVal) {
    int i=l, j=m+1, k=l;

    while (i <= m && j <= r) {
        if (v[i] % maxVal <= v[j] % maxVal) {
            v[k] = v[k] + (v[i] % maxVal)*maxVal;
            k++; i++;
        }
        else {
            v[k] = v[k] + (v[j] % maxVal)*maxVal;
            k++; j++;
        }
    }

    while (i <= m) {
        v[k] = v[k] + (v[i] % maxVal)*maxVal;
        k++; i++;
    }

    while (j <= r) {
        v[k] = v[k] + (v[j] % maxVal)*maxVal;
        k++; j++;
    }

    for (int i=l; i<=r; i++) {
        v[i] /= maxVal;
    }
}

void mergeSortUtil(vector<int>& v, int l, int r, int maxVal) {
    if ( l >= r) {
        return;
    }

    int mid = (l+r)/2;
    mergeSortUtil(v, l, mid, maxVal);
    mergeSortUtil(v, mid+1, r, maxVal);

    mergeVec(v, l, mid, r, maxVal);
}

void mergeSort(vector<int>& v) {
    int maxVal = *max_element(v.begin(), v.end()) + 1;
    mergeSortUtil(v, 0, v.size()-1, maxVal);
}

int main() {
    vector<int> v{7, 4, 3, 2, 5, 1};
    mergeSort(v);
    for_each(v.begin(), v.end(), [](int &x) {cout << x << " ";} );
    cout << endl;
}