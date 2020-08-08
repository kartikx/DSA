/*
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
In my intuitive approach, I was using just countL, and decrementing
it's value (and incrementing a counter by 2) whenever closing bracket 
encountered. I deemed string invalid if countL = 0 and closing encountered.
However, this failed if opening brackets were deeming the string invalid.
For eg. ()()()(((() would return 4*2.

Hence a better way to check whether string is valid, is to countL and countR.
And only increment the counter if both are equal during an iteration.

However if you use this approach, and start iterating from the left, then for a string
pre-pended with a large number of ( for eg. ((((((), the counts would never equate.
Hence, I need to iterate from both directions.
*/

void longestSubstring(string str)
{
    // You need both because you'll only consider a string to be valid
    // if countL = countR.
    int countL=0, countR=0;
    int maxCount = 0;

    // Iterating from the left.
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == '(')
            countL++;
        
        else {
            countR++;
        }
        if (countL == countR) {
                maxCount = max(maxCount, countL*2);
        }
        else if (countR > countL) {
            countL = 0; countR=0;
        }
    }
    cout << "After iterating from the left: " << maxCount << endl;

    countL = 0; countR = 0;
    // Iterate from right;
    for (int i=str.length()-1; i>=0; --i)
    {
        if (str[i] == '(')
            countL++;
        
        else {
            countR++;
        }

        if (countL == countR) {
                maxCount = max(maxCount, countL*2);
        }
        else if (countL > countR) {
            countL = 0; countR=0;
        }
    }
    cout << "After iterating from the right: " << maxCount << endl;

    cout << "Maximum Length is: " << maxCount << endl;
}

int main() {
    string s("((()()()()(((())");
    longestSubstring(s);
}