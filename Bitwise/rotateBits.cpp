/**
 * Given the number of digits used to represent a number,
 * a number(n) and a digit(d), output the number left
 * and right rotated by d.
 * 
 * It's not as easy as simply left and right shifting by d,
 * because the elements popped off from the end must rejoin the
 * other end.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int leftRotate(int n, int d, int max_digits) {
    return (n << d) | (n >> (max_digits-d));
}

int rightRotate(int n, int d, int max_digits) {
    return (n >> d) | (n << (max_digits-d));
}

int main() {
    cout << "Left rotated: " << leftRotate(229, 3, 8) % (1 << 8) << endl;
    cout << "Right rotated: " << rightRotate(229, 3, 8) % (1 << 8) << endl;
}