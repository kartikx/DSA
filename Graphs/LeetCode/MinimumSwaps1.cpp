/**
 * Given an unsorted array, find the minimum
 * number of swaps needed, to sort it.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * My implementation, first store
 * a copy of the array as sorted.
 * Then iterate through this sorted array,
 * if the corresponding index in the original 
 * array is not equal to the element in the sorted
 * array. Then a swap is needed. So find the position
 * of the correct element in the original array,
 * and swap the current element with the correct element.
 * I'm storing a map, to get the indices.
 * Time Complexity : O(NLogN)
 * Space Complexity: 2O(N).
 */
int minSwaps(vector<int>& nums)
{
    // assuming distinct numbers
    unordered_map<int, list<int>> M;

    vector<int> org(nums);
    sort(nums.begin(), nums.end()); // NLogN

    for (int i=0;i<org.size(); i++)
    {   
        M[org[i]].push_back(i);
    }

    int count = 0;

    for (int i=0;i<org.size(); i++)
    {
        int n1 = org[i];    //7
        int n2 = nums[i];   //1

        if (n1 != n2)
        {
            count++;
            int j = M[n2].front();  //O(1)
            M[n2].pop_front();      //O(1)
            org[i] = n2;
            org[j] = n1;
            // not pushing back into n2, as it has been dealt with.
            M[n1].push_back(j);
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {7, 9, 2, 1, 5, 1};
    cout<<minSwaps(nums);
}