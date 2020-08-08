#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
This will start deleting elements from the 
right of the array.
*/
void delSmallerNext(vector<int>& arr, int k)
{
    // populate stack
    stack<int> s;
    for (auto x : arr) {
        s.push(x);
    }
    int count = 0;
    while (s.size() > 1 && count < k) {
        // pluck top two elements out.
        int first = s.top(); s.pop();
        int second = s.top(); s.pop();

        if (first > second) {
            s.push(first);
            cout << "Remove " << second << endl;
            count++;
        }
        else {
            s.push(second);
        }
    }
}

/*
This deletes elements from the left. That is the numbers closer
to the first "peak" are deleted first. The above approach,
deleted from the right, because first I filled up my entire array.

The main idea is that when traversing from L to R, when you encounter
an element, you can't decide whether to remove it or not. That will be decided
in the future if you encounter an element bigger than it.
Hence, you put elements as you encounter them into a stack.
Now the same element that you're at, might be able to remove elements already
present in the stack.
Note that a stack will have a certain number of elements (say n') only if 
all these elements have been found in a decreasing order.
The moment you encounter an element, that is bigger than the top of the stack,
continue to pop elements out so long as the current value is bigger, and the
number of elements removed are < k.
*/
void delSmallerNextGfG(vector<int>& arr, int k)
{
    stack<int> s;
    int count=0;
    for (int i=0; i<arr.size(); i++)
    {
        int curr = arr[i];
        while(!s.empty() && s.top() < curr && count < k) {
            cout << "Remove " << s.top() << endl;
            s.pop();
            count++;
        }
        s.push(curr);
    }


}

int main() {
    vector<int> arr{20, 10, 25, 30, 40};
    delSmallerNextGfG(arr, 2);
}