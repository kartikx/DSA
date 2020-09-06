// Given an Integer, multiply it with 3.5
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// x*3.5 = x*2 + x + x*0.5
int multiply(int x) {
    return (x<<1) + (x) +(x>>1);
}

int main() {
    cout << multiply(2) << endl;
    cout << multiply(5) << endl;
}