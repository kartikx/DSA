/*
https://www.geeksforgeeks.org/the-stock-span-problem/?ref=rp
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getStockSpan(vector<int>& prices)
{
    stack<int> s;
    vector<int> result(prices.size());
    for (int i=0; i<prices.size(); i++)
    {
        if (s.empty())
        {
            result[i] = 1;
        }
        else {
            while(!s.empty() && prices[s.top()] <= prices[i])
            {
                s.pop();
            }
            int topIndex = s.empty() ? -1 : s.top();
            result[i] = i - topIndex;
        }
        s.push(i);
    }

    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> prices = {100, 80,80, 70, 60, 75, 85};
    getStockSpan(prices);
}