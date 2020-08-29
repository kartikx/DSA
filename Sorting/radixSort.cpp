#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool mycompare(int a, int b, int k) {
    int base = (int)pow(10, k);
    return a%base < b%base;
}

// Assumes base to be 10.
void countingSort(vector<int>& v, int num) {
    vector<int> count(10, 0);
    vector<int> output(v.size(), 0);

    for (int i=0; i<v.size(); i++) {
        count[(v[i]/num)%10]++;
    }

    // prefix sum
    for (int i=1; i<count.size(); i++) {
        count[i] += count[i-1];
    }

    // compute output.
    for (int i=v.size()-1; i>=0; i--) {
        output[count[(v[i]/num)%10]-1] = v[i];
        count[(v[i]/num)%10]--;
    }

    for (int i=0; i<v.size(); i++)
        v[i] = output[i];
}

void radixSort(vector<int>& v) {
    // Find maximum element.
    int maxEle = INT_MIN;
    for (auto x : v) {
        maxEle = max(x, maxEle);
    }

    int count = 0;
    // find number of digits in maxEle.
    while (maxEle != 0) {
        maxEle /= 10;
        count++;
    }

    for (int i=0; i<count; i++) {
        countingSort(v, (int)pow(10, i));
    }
}

int main() {
    vector<int> v{473, 267, 445};
    radixSort(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}