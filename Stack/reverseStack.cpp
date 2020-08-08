#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Imagine a Stack of Tennis Balls
 * 1
 * 2
 * 3
 * 4
 * You want to reverse this (1 is at the top).
 * First just keep plucking things out and storing in your right hand 1 -> 2 -> 3 -> 4
 * Now you would like to insert these plucked elements back in a reverse fashion, i.e.
 * even though 4 is inserted first, it should remain at the top of the can.
 * So Insert 4.
 * When Inserting 3, first pull 4 out, then insert 3.
 * When Inserting 2, pull 4 and 3 out, insert 2 then 3 then 4.
 * SO basically when inserting, first pull everything out, insert value, and then push everything back in 
 * the order you pulled out.
 */

void insertAtBottom(stack<int>& s, int val)
{
    if (s.empty()) {
        s.push(val);
        return;
    }

    int topVal = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(topVal);
}

void reverseStack(stack<int>& s)
{
    if (s.empty())
        return;

    int topVal = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topVal);
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    reverseStack(s);

    while(!s.empty())
    {
        cout << s.top() << " " ;
        s.pop();
    }
}