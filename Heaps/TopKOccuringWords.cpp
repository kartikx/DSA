#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class comp {
    public:
        bool operator()(pair<int, int> p1, pair<int, int> p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
};

void findTopK(vector<string>& keys, int k) {

    if (k >= keys.size()) {
        return;
    }

    // Space Complexity: O(N).
    unordered_map<string, pair<int, int>> m;

    // Time Complexity: O(N).
    for (int i=0; i<keys.size(); ++i) {
        string str = keys[i];
        if (m.count(str) > 0) {
            m[str].first++;
        }
        else {
            m[str] = {1, i};
        }
    }

    // Min-Heap. Space Complexity: O(K).
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    // Time Complexity: O(K).
    auto it = m.begin();
    for (int i=0; i<k; i++) {
        if (it == m.end()) {
            cout << "Insufficient Number of Distinct Words!";
            return;
        }
        pq.push(it->second);
        it++;
    }

    // Time Complexity: O(N-K).
    comp c;
    while (it != m.end()) {
        if (c(it->second, pq.top())) {
            pq.pop();
            pq.push(it->second);
        }
        it++;
    }

    cout << k << " most frequent words are: " << endl;

    while (!pq.empty()) {
        cout << keys[pq.top().second] << " : " << pq.top().first << endl;
        pq.pop();
    }
}

int main() {
    vector<string> keys = {"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"};
    
    findTopK(keys, 4);
}