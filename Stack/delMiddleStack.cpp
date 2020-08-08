#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void delMiddle(stack<int>& s, int n, int& count) {
//     if (s.empty()){
//         count = n;
//         return;
//     }

//     int curr = s.top();
//     s.pop();
//     delMiddle(s, n+1, count);

//     if (n == ceil((float)count/2) - 1) {
//         return;
//     }

//     s.push(curr);
//     return;
// }

// In this n is the counter, and count is the total number of elements.
// If you are known the total number of elements, then you don't need
// to traverse till the bottom.
void delMiddle(stack<int>& s, int n, int count) {
    if (s.empty()){
        return;
    }

    if (n == ceil((float)count/2) - 1) {
        s.pop();
        return;
    }

    int curr = s.top();
    s.pop();
    delMiddle(s, n+1, count);
    s.push(curr);
}


int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    delMiddle(s, 0, s.size());

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}