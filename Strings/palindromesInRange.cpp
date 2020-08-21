// https://www.geeksforgeeks.org/program-print-palindromes-given-range/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i=0; int j=s.length()-1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

// void printPalindromesInRange(int a, int b) {
//     for (int i=a; i<=b; i++) {
//         if (isPalindrome(to_string(i))) {
//             cout << i << " ";
//         }
//     }
//     cout << endl;
// }

int numberOfDigits(int s) {
    int i=1;
    while ((int)(s/pow(10, i)) != 0) {
        i++;
    }
    return i;
}

void generatePalindrome(int a, int b, int index, int iterateOver, int c, string& s) {
    if (index >= iterateOver) {
        int num = stoi(s);
        if (num >= a && num <= b) {
            cout << num << endl;
        }
        return;
    }

    int startCount = (index == 0) ? 1 : 0 ;

    for (int i=startCount; i<=9; i++) {
        string s_copy(s);
        ostringstream oss;
        if (index == iterateOver - 1 && c%2 == 1) {
            oss << i;
        }
        else {
            oss << i << i ;
        }
        s_copy.insert(index, oss.str());
        generatePalindrome(a, b, index+1, iterateOver, c, s_copy);
    }
}

void printPalindromesInRange(int a, int b) {
    int numA = numberOfDigits(a);
    int numB = numberOfDigits(b);

    // c stores the number of digits in my generated string.
    for (int c = numA; c <= numB; c++) {
        int lby2 = ceil(c/2.0);
        string s("");
        generatePalindrome(a, b, 0, lby2, c, s);
    }
}

int main() {
    printPalindromesInRange(9, 287);
}