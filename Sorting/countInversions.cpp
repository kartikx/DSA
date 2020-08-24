#include <iostream>
#include <vector>
using namespace std;

// O(N^2) approach.
int countInversionsNaive(vector<int>& v) {
    int inversionCount = 0;
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < v[i]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

int mergeVec(vector<int>& v, int l, int m, int r) {

    int i=l; int j=m+1; int k=0;
    int count = 0;
    vector<int> output(r-l+1, 0);
    while (i <= m && j <= r) {
        if (v[i] <= v[j]) {
            output[k++] = v[i++];
        }
        else {
            count += (m - i + 1);
            output[k++] = v[j++];
        }
    }

    while (i <= m) {
        output[k++] = v[i++];
    }
    while (j <= r) {
        output[k++] = v[j++];
    }

    k=0;
    for (int i=l; i<=r; i++) {
        v[i] = output[k++];
    }

    return count;
}

int countInversionsUtil(vector<int>& v, int l, int r) {
    if (l >= r) {
        return 0;
    }

    int mid = (l+r)/2;
    int i1 = countInversionsUtil(v, l, mid);
    int i2 = countInversionsUtil(v, mid+1, r);

    int i3 = mergeVec(v, l, mid, r);

    return i1 + i2 + i3;
}

int countInversions(vector<int>& v) {
    return countInversionsUtil(v, 0, v.size()-1);
}

int main() {
    vector<int> v{2, 1, 4, 7, 1, 3, 8};
    cout << countInversions(v) << endl;
}