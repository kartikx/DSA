// https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSubsequence(string& s1, string& s2, int i, int j) {
    // base case.
    if (j >= s2.length() && i <= s1.length()) {
        return 1;
    }
    int ans = 0;
    for (int c = i; c < s1.length(); c++) {
        if (s1[c] == s2[j]) {
            ans += countSubsequence(s1, s2, c+1, j+1);  
        }
    }
    return ans;
}

int main() {
    string s1("GeeksForGeeks");
    string s2("Gks");
    cout << countSubsequence(s1, s2, 0, 0);
    transform(s1.begin(), s1.end(), s1.begin(), [](char ch){return tolower(ch);});
    cout << s1 << endl;
}