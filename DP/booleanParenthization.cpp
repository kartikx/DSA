#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool computeVal(char op1, char op2, char op) {
    bool b1 = op1 == 'T' ? true : false;
    bool b2 = op2 == 'T' ? true : false; 

    switch (op) {
        case '&':
            return b1&b2;            
        case '|':
            return b1|b2;
        case '^':
            return b1^b2;
    }
}

// returns b2 such that b1 op b2 = TRUE.
bool reverseVal(bool b1, char op) {
    
}

int parenthUtil(string& expr, int l, int r, bool expectedValue) {
    // base case.

    // if F& -> don't proceed down.
    // if T| -> bracket however you want.
    // if F^ -> T
    // if T^ -> F


    // a ^ b & c .. the sub-exp1 corresponds to (a^b) & c.
    // exp1 is the expected value of the sub-expression to make the 
    // resulting total expression true when I bracket around the first operator.
    bool val1 = computeVal(expr[l], expr[l+2], expr[l+1]);
    bool val2 = (expr[l] == 'T')?true:false;
    bool exp1, exp2;
    int ans1=-1, ans2=-1;
    switch (expr[l+3]){
        case '&':
            if (val1){
                ans1 = parenthUtil(expr, l+4, r, true);
            }
            break;
        case '|':
            if (!val2) {
                ans2 = parenthUtil(expr, l+4, r, true); 
            }
            else {
                ans2 = 2 ;// ?
            }
            break;
        case '^':
    }
    return parenthUtil(expr, l+4, r, exp1) + parenthUtil(expr, l+2, r, exp2);

}

void boolParenthization() {
    // if l < 1, return 0
    // if l == 1, return 1 if it matches the expected value.
    // if l == 3, return 1 if the operation result matches the expected value.
    // else l >= 5, use recursion.
    // First extract first 4 characters.
}

int main() {
    cout << 
}