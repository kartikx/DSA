/**
 * Given an array of numbers.
 * For every number find the first number in the part of
 * the array ahead of it, that's greater than the number.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
The basic Idea is that if you're scanning the array from Left to Right,
then for every element that you encounter, the answer for it will be received
sometime in the Future. Hence, you need to store it somewhere, in order to
process it later.
Consider 2 1 3 4
You push 2 to the stack.
You get to 1, 1 can not be the answer to 2.
Since 1 needs to be processed as well, push it onto the stack.
You get to 3, 3 > 1 so remove 1 from stack, and 1s answer is 3.
Similarly for 2, 2s answer is 3. Stack is empty. Push 3.

Since it's asked to find the next "FIRST" greatest element, the only reason
why you would have multiple numbers in your stack is if the numbers appeared
in strictly descending order in the array. Once a number greater than "ANY"
number is encountered, even if the number in stack is present somewhere in the middle,
it and all numbers above it on the stack would be removed. Because the numbers above
it must be smaller than the middle number.

void nextGreaterElement(vector<int>& nums, vector<int>& res)
{
    stack<pair<int,int>> s;
    for (int i=0; i<nums.size(); i++)
    {
        int curr = nums[i];
        while(!s.empty() && s.top().first < curr) {
            // cout << "Next greater for " << s.top().first << " is " << curr << endl;
            res[s.top().second] = curr;
            s.pop();
        }
        s.push({curr, i});
    }

    while(!s.empty())
    {
        // cout << "Next greater for " << s.top() << " is " << -1 ;
        res[s.top().second] = -1;
        s.pop(); 
    }
}
*/

/*
This answer is further optimized to allow printing of the elements
in order. If you use normal approach, since you are using in stack, some elements
that appeared first, may be processed later.
For in-order, you can either put the Index into your stack and use the same approach,
or you can traverse from right to left.
*/
void nextGreaterElement(vector<int>& nums, vector<int>& res)
{
    stack<int> s;

    for (int i = nums.size() - 1; i >= 0; --i) {
        int curr = nums[i];
        while (!s.empty() && s.top() <= curr)
        {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        else {
            res[i] = -1;
        }
        s.push(curr);
    }
}

int main()
{
    vector<int> nums{1, 3, 2, 4, 7, 5, 0, 4};
    vector<int> res(nums.size(), 0);
    nextGreaterElement(nums, res);

    for (int i=0;i<nums.size();i++) {
        cout << nums[i] << "-" << res[i] << " ";
    }
}