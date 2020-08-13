#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
*/

int returnSmallestFrequency(string s)
{
    sort(s.begin(), s.end());
    char first = s.front();
    int freq = 0;
    for (char ch: s)
    {
        if (ch != first)
            break;
        freq++; 
    }
    return freq;
}

void compareStrings(string s1, string s2)
{
    vector<string> S1;
    vector<string> S2;

    // Tokenized the strings into vectors.
    stringstream ss(s1);
    string inter;
    while(getline(ss, inter, ',')){
        S1.push_back(inter);
    }

    stringstream ss2(s2);
    while(getline(ss2, inter, ',')){
        S2.push_back(inter);
    }

    // Store the smallestFreq of each String as a number into vector.
    vector<int> freq1(S1.size());
    for (int i=0;i<freq1.size(); i++)
    {
        freq1[i] = returnSmallestFrequency(S1[i]);
    }

    // Do the same for freq2 (string being compared to).
    vector<int> freq2(S2.size());
    for (int i=0;i<freq2.size(); i++)
    {
        freq2[i] = returnSmallestFrequency(S2[i]);
    }

    // Now for every element in freq2, I have to find the
    // number of elements smaller than it present in freq1.
    // Sorting allows me to use upper bound.
    sort(freq1.begin(), freq1.end());

    for (int i=0; i<freq2.size(); i++)
    {
        int x = freq2[i];
        auto it = upper_bound(freq1.begin(), freq1.end(), x-1);
        freq2[i] = distance(freq1.begin(), it);
    }
}

/*
A better approach would be to use prefix sums.
So basically if your s2 string has f = 3,
you want n(2) + n(1) + n(0).
Firstly store n(i) in an array, note that
i will be from 0 .. 10 only.
Then use prefix sums instead of having
to compute the sums of all individuals always.
*/

int main() {
    // string s1 = "abcd,aabc,bd";
    // string s2 = "aaa,aa";

    // compareStrings(s1, s2);
}