#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void createAllSequencesUtil(list<char>& charset, string& curr, vector<string>& output)
{
    if (charset.empty())
    {
        output.push_back(curr);
        return;
    }

    int i=0;
    int size = charset.size();
    while (i < size) {
        string scopy(curr);
        int currVal = charset.front();
        scopy.push_back(currVal);
        charset.pop_front();
        createAllSequencesUtil(charset, scopy, output);
        charset.push_back(currVal);
        i++;
    }
    return;
}

void createAllSequences(string& s)
{
    // assuming unique.
    list<char> charset;
    for (char ch : s)
        charset.push_back(ch);
    vector<string> output;
    string curr("");
    createAllSequencesUtil(charset, curr, output);

    for (auto str : output)
        cout << str << endl;
}

int main() {
    string s("279");
    createAllSequences(s);
}