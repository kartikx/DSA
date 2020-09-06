/**
 * Find the median for every element in a stream
 * of integers.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The main idea is to construct two heaps.
 * A max-heap for the lesser half of the sorted array,
 * and a min-heap for the greater half.
 * At any moment, if the sizes are equal then you'll get
 * the median using the average of the top elements of each heap.
 * If sizes are not equal (i.e. they differ by 1), then the answer
 * would be top of the one with greater size.
 */
void findMedian(vector<int>& v) {
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    float median = 0;

    for (int i=0; i<v.size(); i++) {
        int curr = v[i];

        if (l.size() < r.size()) {
            // some element must move into the left.

            if (r.top() < curr) {
                l.push(r.top());
                r.pop();
                r.push(curr);
            }
            else {
                l.push(curr);
            }

            median = (l.top() + r.top())/2.0;
        }
        else  if (l.size() > r.size()) {
            if (l.top() > curr) {
                r.push(l.top());
                l.pop();
                l.push(curr);
            }
            else {
                r.push(curr);
            }
            median = (l.top() + r.top())/2.0;
        }

        else {
            // should insert to appropriate container, answer
            // would be top of the newly inserted to container.
            if (curr < median) {
                l.push(curr);
                median = l.top();
            }
            else {
                r.push(curr);
                median = r.top();
            }
        }

        cout << median << " ";
    }

    cout << endl;
}

int main() {
    vector<int> v{1, 2, 3, 4};
    findMedian(v);
}