/*
Given an array, count subarrays
where second highest element, appears before the highest.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
The brute force approach is to get all sub-arrays
and check for them. Instead, see from the POV of the highest and
second-highest element in the subarray.
If you find the next Greater Element of the second-highest element,
it will be the highest element.
Also the next Greater Element on the left should be -1 (in the sub-array considered).

More generally, we could consider each element one by one and compute it's LGR and RGR.
Then you can consider all sub-arrays starting from [LGR+1 to curr] and ending at RGR.
This will confirm that the highest element is RGR and second-highest is curr.

You can't go beyond RGR for this current element, as the very next element after RGR might be just
less than RGR, which would make it the second highest.
*/

void rightGreater(vector<int> arr, vector<int>& rg)
{
    stack<int> s;

    for (int i=arr.size()-1;i>=0; --i)
    {
        int curr = arr[i];
        while(!s.empty() &&  curr > arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            rg[i] = -1;
        }
        else {
            rg[i] = s.top();
        }
        s.push(i);
    }
}

void leftGreater(vector<int>& arr, vector<int>& lg)
{
    stack<int> s;

    for (int i=0;i<=arr.size(); ++i)
    {
        int curr = arr[i];
        while(!s.empty() &&  curr > arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            lg[i] = -1;
        }
        else {
            lg[i] = s.top();
        }
        s.push(i);
    }
}
void countSubArrays(vector<int>& arr)
{
    vector<int> lg(arr.size(), 0);
    vector<int> rg(arr.size(), 0);

    leftGreater(arr, lg);
    rightGreater(arr, rg);

    int count=0;
    for (int i=0;i<arr.size(); i++)
    {
        if (rg[i] != -1)
        {
            count += (i - (lg[i] + 1) + 1);
        }
    }
    cout << count << endl;
}

int main() {
    vector<int> arr = {2, 1, 3, 5, 7};
    countSubArrays(arr);
}