// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numSequencesUtil(string& s, int index, char lastChar) {
    if (index >= s.length()) {
        if (lastChar != 'c')
            return 0;
        return 1;
    }

    int includeChar=0, skipChar=0;

    if ((!lastChar && s[index]=='a') || (s[index] - lastChar == 0 || s[index] - lastChar == 1)) {
        includeChar = numSequencesUtil(s, index+1, s[index]);
    }
    skipChar = numSequencesUtil(s, index+1, lastChar);

    return includeChar + skipChar;
}

int numSequences(string& s) {
    return numSequencesUtil(s, 0, '\0');
}

// Optimized Iterative Approach.
/*
 * Notice that to build the substrings, I could first select the number of
 * ways to select A, then number of ways to select B and then number of ways to select C,
 * and add them up. Obviously I can't do this just once at the end by using the frequencies
 * as order matters.
 */
int numSequencesGfG(string& s) {

}

int main() {
    string s("abcabc");
    cout << "Number of possible subsequences are: " << numSequences(s) << endl;
}