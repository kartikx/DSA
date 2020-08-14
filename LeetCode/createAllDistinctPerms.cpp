/*
Find all distinct perms if
the given string has duplicate characters.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
In each recursive call, keep track of the characters that
you have swapped. Time Complexity: k + (k)(k-1) + (k^2)(k-2) + ... + (k^(k-2))(2).
Leaves aren't taking any space, i just return from them.
*/
void getAllDistinctPermsUtil(string& s, int index, vector<string>& output)
{
    if (index == s.length() - 1)
    {
        output.push_back(s);
        return;
    }

    unordered_set<char> swappedChars;

    for (int i=index; i<s.length(); ++i)
    {
        if (swappedChars.count(s[i]) == 0) {
            string s_copy(s);
            swappedChars.insert(s[i]);
            swap(s_copy[index], s_copy[i]);
            getAllDistinctPermsUtil(s_copy, index+1, output);
        }
    }

    return;
}

void getAllDistinctPerms(string& s)
{
    vector<string> output;
    getAllDistinctPermsUtil(s, 0, output);
    cout << "Size is: " << output.size() << endl;
    for (auto x : output)
        cout << x << endl;
}

int main() {
    string s = "ABCA";
    getAllDistinctPerms(s);
}