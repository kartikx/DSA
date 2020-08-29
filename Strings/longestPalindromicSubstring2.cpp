/*
https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
The longest Palindrome will be either of Odd Length,
or Even Length.
Generating an Odd Length Pal. is easy, start from a letter
as centre, and expand in both directions.
For Even, select consecutive pairs, s.t. they are equal,
and then expand in both directions.

You can come to this approach by thinking from the Longest Palindromic
Subsequence POV. Since I'm not allowed to skip characters in between,
I shouldn't be starting from the ends. Hence, starting from the middle
and expanding outwards is the logical solution. Now two cases Odd , Even.
*/
void lPS(string& s) {
    int maxLen = -1;
    pair<int, int> p{0, 0};

    // Odd Length
    for (int i=0; i<s.length(); i++) {
        int currCount = 1;
        int l = i-1; int r = i+1;
        while (l>=0 && r<s.length() && (s[l] == s[r])) {
            currCount+=2;
            l--;
            r++;
        }
        if (currCount > maxLen) {
            maxLen = currCount;
            p = {l+1, r-1};
        }
    }

    // Even Length
    for (int i=1; i<s.length(); ++i) {
        int r = i;
        int l = i-1;
        int currCount = 0;
        while (l >= 0 && r<s.length() && s[l] == s[r]) {
            currCount+=2;
            l--; r++;
        }
        if (currCount > maxLen) {
            maxLen = currCount;
            p = {l+1, r-1};
        }
    }

    // Print out the LPS
    for (int i=p.first; i<=p.second; i++) {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    string s;
    for (int i=0; i<5; i++) {
        cin >> s;
        lPS(s);
    }
}