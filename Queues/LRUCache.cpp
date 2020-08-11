#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        LRUCache(int n) {
            this->csize = n;
        }

        void refer(int x) {
            // x is not present in Cache.
            if (m.find(x) == m.end()) {
                cout << "Value not present in Cache, accessing from Database.." << endl;
                // cache is full.
                if (dq.size() == this->csize) {
                    cout << "Cache is full, Removing the last element from Cache.." << endl;
                    m.erase(dq.back());
                    dq.pop_back();
                }
            }

            // x is present in cache.
            else {
                cout << "Cache hit, accessing from the Cache.." << endl;
                dq.erase(m[x]);
            }

            dq.push_front(x);
            m[x] = dq.begin();

            /**
             * An update is not required when we insert, because we're inserting
             * to the Front of the List. Initially when there was one element,
             * it pointed to the list begin. When another element is added, it
             * points to the list begin of the new list. So it's not as if both
             * elements are pointing to the beginning of the new list.
             * Furthermore, the old iterators don't get invalidated when inserting
             * into the front.
             */
        }

        void display() {
            cout << "Printing the Cache.." << endl;
            for (auto it = dq.begin(); it!=dq.end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }

    private:
        list<int> dq;
        unordered_map<int, list<int>::iterator> m;
        int csize;
};

int main() {
    LRUCache lru(3);
    lru.refer(1);
    lru.refer(2);
    lru.refer(3);
    lru.refer(1);
    lru.refer(1);
    lru.refer(4);
    lru.display();
}
