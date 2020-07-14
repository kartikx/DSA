#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums)
{
    vector<pair<int, int>> V(nums.size());
    for(int i=0; i < nums.size() ; i++)
    {
        // These store mapping of number to index in the original array.
        V[i].first = nums[i];
        V[i].second = i;
    }

    sort(V.begin(), V.end());

    vector<bool> visited(V.size(), false);

    int ans = 0;

    for (int i=0; i<V.size(); i++)
    {
        if (i == V[i].second || visited[i])
            continue;
        int count = 0;
        int j = i;
        while (!visited[j])
        {   
            visited[j] = true;
            j = V[j].second;
            count++;
        }
        if (count > 0)
            ans += count-1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 9, 2, 1, 5, 1};
    cout<<minSwaps(nums);
}