#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1 2 3
// currVal = 1, s = 2 3
// currVal = 2 , s = 3
// newVal = 3, s = 2
// s = 3, 2
// newVal = 3, s = 1, 2
// s = 2, 1

void insertSorted(stack<int>& s, int val) {

    if (s.empty() || val > s.top()) {
        s.push(val);
        return;
    }

    // the top Value is bigger, so propagate val down.
    int newVal = s.top();
    s.pop();
    insertSorted(s, val);
    s.push(newVal);
}

void sortStack(stack<int>& s, int& n) {
    n++;
    if (s.size() <= 1) {
        return;
    }

    int currVal = s.top();
    s.pop();

    sortStack(s, n);

    /*
    My initial intuition was that If currVal is smaller than top of
    the (n-1) stack, then I should replace currVal and top of stack,
    and then redo sortStack for (n-1), however that's suboptimal.
    Since (n-1) stack is sorted, I just have to find the correct position
    of the currVal, which can be done just by iterating from top to bottom.
    */
    insertSorted(s, currVal);
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int n=0;
    sortStack(s, n);

    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
}