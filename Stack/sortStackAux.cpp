/*
Use a Temporary Stack, to sort a Stack. Sorting means that
the greatest element is at the top.

As an extreme case, consider when the Stack is completely
reverse sorted. In that case, all that's needed is to use
the temporary stack, to reverse the Stack.

So you can push elements from top of Stack to Temp, if the element
is > top of Temp. If not, then you need to find it's correct position.
You can do this, by removing elements from Temp (and storing them into
Stack).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
O(N*2) Time, O(N) space
*/
void sortStackUtil(stack<int>& s, stack<int>& t)
{
    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (t.empty() || curr > t.top()) {
            t.push(curr);
        }
        else {
            while(!t.empty() && curr < t.top()) {
                s.push(t.top());
                t.pop();
            }
            t.push(curr);
        }
    }
}

void sortStack(stack<int>& s)
{
    if (s.empty())
        return;
    
    stack<int> t;
    sortStackUtil(s, t);

    cout << "Sorted stack is \n";
    while(!t.empty()) {
        cout << t.top() << " " ;
        t.pop();
    }
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(0);
    s.push(3);
    sortStack(s);
}