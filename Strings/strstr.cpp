#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mystrStr(const string A, const string B) {
    if (A.empty() || B.empty())
        return -1;

    for (int i=0; i<(int)A.length()-(int)B.length()+1; i++){
        int j=0;
        int index=i;
        bool flag = true;
        for (j; j<B.length(); j++, index++){
            if (B[j] != A[index]){
                flag = false;
                break;
            }
        }
        if (flag){
            return i;
        }
    }
    
    return -1;
}

int main() {
    cout << mystrStr("b", "baba") << endl;
}