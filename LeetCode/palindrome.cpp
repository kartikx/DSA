#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s)
{
    int start = 0, end = s.length() -1;

    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool isRotatedPalindrome(string& s)
{
    for (int i=0; i<s.length(); ++i)
    {
        rotate(s.begin(), s.begin()+1, s.end());
        if (isPalindrome(s))
            return true;
    }
    return false;
}

int main() {
    string s;
    for (int i=0; i<10; i++){
        cin >> s;
        cout << isRotatedPalindrome(s) << endl;
    }
}