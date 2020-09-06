#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fooUtil(string& s1, string& s2, string& s, int i1, int i2, int i) {
    if (i == 0) {
        return 1;
    }

    if (i1 < 0 || i2 < 0) {
        return 0;
    }

    int ans = 0;

    if (s1[i1] == s[i]) {
        ans += fooUtil(s1, s2, s, i1-1, i2, i-1);
    }

    if (s2[i2] == s[i]) {
        ans += fooUtil(s1, s2, s, i1, i2-1, i-1);
    }

    // ans += fooUtil(s1, s2, s, i1-1, i2, i) + fooUtil(s1, s2, s, i1, i2-1, i);

    return ans;
}

int foo(string& s1, string& s2, string& s) {

    return fooUtil(s1, s2, s, s1.length()-1, s2.length()-1, s.length()-1);

}

int main() {

    string s1 = "abd";
    string s2 = "bcd";
    string s = "abcd";

    cout << foo(s1, s2, s);
}