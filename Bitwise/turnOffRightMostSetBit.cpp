// Turn off the Right Most *SET* bit

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 7;
    // (a-1) has all bits including and after the right most set bit flipped.
    // all bits after the right most set bit must be zeros
    // right side of x would be of the form 10000 and for x-1 it becomes 01111.
    // So just take an and.
    a = a & (a-1);
    cout << a << endl; 
}