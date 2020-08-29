#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int, int> m;
    m.insert({0, 10});
    m.insert({2, 20});
    m.insert({0, 100});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({2, 20});

    auto itpair = m.equal_range(0);
    for (auto it = itpair.first; it != itpair.second; it++) {
        cout << it->first << " " << it->second << endl;
    }
}