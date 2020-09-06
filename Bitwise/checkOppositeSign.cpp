#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = -1, b=100;
    // I have to check using the Sign Bit.
    if ((a^b) < 0) {
        cout << "Opposite Signs" << endl;
    }
    else {
        cout << "Same Sign" << endl;
    }
}