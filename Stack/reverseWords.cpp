/*
Given a sentence, reverse each word.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(N) space and O(N) time where N is number of characters in sentence.
void reverseWordsNaive(string s)
{
    stringstream ss(s);
    vector<string> words;
    string word;
    while (getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    string revSentence;
    for (string word : words) {
        reverse(word.begin(), word.end());
        revSentence += word;
        revSentence += " ";
    }

    cout << revSentence << endl;
}

// O(W) space and O(N) time, when W is length of max word.
void reverseWords(string s)
{
    stack<char> word;
    for (auto it = s.begin() ; it != s.end() ; it++)
    {
        if (*it == ' ')
        {
            while(!word.empty())
            {
                cout << word.top() ;
                word.pop();
            }
            cout << " ";
        }
        else {
            word.push(*it);
        }
    }

    while(!word.empty())
    {
        cout << word.top() ;
        word.pop();
    }

    cout << endl;
}

int main() {
    reverseWords("Hello world this is Kartik");
}