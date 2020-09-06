#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeIntervals(map<int, int>& intervals) {
        if (intervals.empty()){
            return ;
        }
        auto it1 = intervals.begin();
        auto it2 = next(it1);
        
        while (it2 != intervals.end()) {
            if (it2->first < it1->second) {
                if (it2->second > it1->second) {
                    it1->second = it2->second;
                }
                intervals.erase(it2);
                it2 = next(it1);
            }
            else {
                it1++;
                it2++;
            }
        }
}

int main() {

}