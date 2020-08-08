#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoiRec(int n, int s, int m, int e) {
    if (n == 1) {
        cout << "Move from " << s << " to " << e << endl;
        return;
    }

    towerOfHanoiRec(n-1, s, e, m);
    cout << "Move from " << s << " to " << e << endl;
    towerOfHanoiRec(n-1, m, s, e);
}

/*
Don't try to think recursively, and then convert
it to a stack. Instead try to think iteratively,
step by step what you are doing.

Try for n = odd, what the i%3 operation does for all i.
It would be opposite for even.

To improve code, you could have a separate function, responsible
just for moving between two stacks. That function would also
check which of the two stacks to move to.
*/
void towerOfHanoiIter(int n) {
    vector<stack<int>> stacks;
    for (int i=n; i>0; --i) {
        stacks[0].push(i);
    }

    bool even = (n%2 == 0)

    for (int i=0; i<pow(2, n)-1; i++) {
        if (i%3 == 0){
            if (even) {
                if (stack[1].empty() || stack[1].top() > stack[0].top()) {
                    stack[1].push(stack[0].top())
                    stack[0].pop();
                }

                if (stack[0].empty() || stack[1].top() < stack[0].top()) {
                    stack[0].push(stack[1].top())
                    stack[1].pop()
                }
            }
            else {
                if (stack[2].empty() || stack[2].top() > stack[0].top()) {
                    stack[2].push(stack[0].top())
                    stack[0].pop();
                }

                if (stack[0].empty() || stack[2].top() < stack[0].top()) {
                    stack[0].push(stack[2].top())
                    stack[2].pop()
                }
            }
        }

        if (i%3 == 1){
        }
        if (i%3 == 2){
        }
    }
}

int main() {
    towerOfHanoiRec(3, 0, 1, 2);
}