#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int add1(int num) {
    // Toggle all bits until rightmost 1.
    int m = 1;
    while (num & m) {
        num ^= m;
        m <<= 1;
    }
    num ^= m;
    return num;
}

int main() {
    int num = 3;
    int c = 1;
    int sum = add1(num);
    cout << sum;
}