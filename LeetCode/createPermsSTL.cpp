/*
Create all permutations (non-distinct allowed)
by using std::rotate.

The main idea is that you'll pass in an empty string that will
contain the final output.
Consider the input string, the first character of the output string
can be any of the characters of the input string. This is achieved
by pushing in the first character of the input string into the output
string, and then rotating the input string. The rotation will allow
that every time a new character is present at the first position. Hence,
all letters get considered.
Simple iteration is not sufficient, because I also need to pass down to the 
recursive call this string with the first position removed. If i didn't rotate
removing from the string would have been difficult.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void createAllPermutations(string s, string output)
{
    if (s.size() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i=0; i<s.length(); ++i)
    {
        createAllPermutations(s.substr(1), output+s[0]);

        rotate(s.begin(), s.begin()+1, s.end());
    }
}

int main() {
    createAllPermutations("kar", "");
}