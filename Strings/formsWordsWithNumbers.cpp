// Given a vector of integers, form all words you may form
// by replacing the integer with the letter.
// https://www.techiedelight.com/combinations-of-words-formed-replacing-given-numbers-corresponding-english-alphabet/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValidNum(int num) {
    if (num>=1 && num <= 26) {
        return true;
    }
    return false;
}

void formWordsUtil(vector<int>& numbers, int index, string currString) {
    if (index >= numbers.size()) {
        cout << currString << endl;
        return;
    }

    int currNum = 0;
    for (int i=index; i<numbers.size(); ++i) {
        currNum = currNum*10 + numbers[i];
        if (isValidNum(currNum)) {
            currString.push_back('a'+currNum-1);
            formWordsUtil(numbers, i+1, currString);
            currString.pop_back();
        }
        else {
            return;
        }
    }
}

void formWords(vector<int>& numbers) {
    if (numbers.empty()) {
        return;
    }

    formWordsUtil(numbers, 0, "");
}

int main() {
    vector<int> nums = {1, 2, 2, 1};
    formWords(nums);
}