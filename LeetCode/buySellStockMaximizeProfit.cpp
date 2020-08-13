/*
https://www.geeksforgeeks.org/stock-buy-sell/
You're allowed to buy and sell multiple times.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Method I use on leetCode is to keep computing
successive differences, and add if >= 0.
Another method could be to find the first local minima and
first local maxima and compute their difference, continue
to do this in array.
*/

void buySellStock(vector<int>& prices)
{
    int i=0;
    int n = prices.size();

    while (i<n)
    {
        // find local minima
        while( (i < n-1) && (prices[i+1] <= prices[i]))
            ++i;
        int localMinima = i;

        // find local maxima
        while( (i < n-1) && (prices[i+1] >= prices[i]))
            ++i;
        int localMaxima = i;
        i++;
        cout << "Minima: " << localMinima << " " << "Maxima: " << localMaxima << endl;
    }
}

int main() {
    vector<int> prices = {40, 30, 30, 20, 50, 60, 60, 70, 20, 30, 40, 50, 30, 20, 10};
    buySellStock(prices);
}