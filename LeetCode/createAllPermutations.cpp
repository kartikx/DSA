/*
Given a string, find all permutations.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getAllPermsUtil(string& s, int index, vector<string>& outputs)
{
    if (index == s.length() - 1) {
        outputs.push_back(s);
        return;
    }

    for (int i=index; i<s.length(); i++){
        string s_copy(s);
        if (index == i || s[index] != s[i])
        {
            swap(s_copy[index], s_copy[i]);
            getAllPermsUtil(s_copy, index+1, outputs);
        }
    }
}

void getAllPermutations(string& s)
{
    vector<string> outputs;
    getAllPermsUtil(s, 0, outputs);

    cout << outputs.size() << endl;
}

int main() {
    string s = "kartik";
    getAllPermutations(s);
}