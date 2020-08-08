#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findSmallerRight(vector<int>& arr, vector<int>& smallerRight)
{
    stack<int> s;

    for (int i=arr.size()-1; i>=0; --i)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
        {
            s.pop();
        }

        if (s.empty()){
            smallerRight[i] = arr.size();
        }
        else {
            smallerRight[i] = s.top();
        }

        s.push(i);
    }
}

void findSmallerLeft(vector<int>& arr, vector<int>& smallerLeft)
{
    stack<int> s;

    for (int i=0; i<arr.size(); ++i)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
        {
            s.pop();
        }

        if (s.empty()){
            smallerLeft[i] = -1;
        }
        else {
            smallerLeft[i] = s.top();
        }
        s.push(i);
    }
}

vector<int> findMaximumOfMinimumWindows(vector<int>& arr)
{
    vector<int> result(arr.size(), -1);
    vector<int> smallerLeft(arr.size());
    vector<int> smallerRight(arr.size());

    findSmallerLeft(arr, smallerLeft);
    findSmallerRight(arr, smallerRight);

    for (int i=0;i<arr.size();++i)
    {
        int maxSize = (smallerRight[i]-1) - (smallerLeft[i] + 1) + 1;

        for (int j = 0; j<maxSize; ++j)
        {
            if (arr[i] > result[j])
                result[j] = arr[i];
        }
    }
    return result;
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result;
    result = findMaximumOfMinimumWindows(arr);

    for (auto x : result) {
        cout << x << " ";
    }
}