/**
 * Starting from the right, swap each pair of bits.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bitset<32> bs(n); 
        for (int i=0; i<8; i+=2) {
            bool temp = bs[i];
            bs[i] = bs[i+1];
            bs[i+1] = temp;
        }
        cout << bs.to_ulong() << endl;
    }
}