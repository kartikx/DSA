/*
bool l = (2*i+1 < A.size())
bool r = (2*i+2 < A.size())

largest = i;
if (l && A[left] > A[i]) {
    largest = left;
}

if (r && A[right] > A[largest]) {
    largest = right;
}

swap(A[largest], A[i]);
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int>& heap, int i, int size) {
    if (i >= size)
        return;
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] > heap[i]) {
        largest = left;
    }
    
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (i != largest)
    {
        swap(heap[i], heap[largest]);
        return max_heapify(heap, largest, size);
    }
    return ;
}

void build_heap(vector<int>& heap) {
    if (heap.size() <= 1)
        return;
    
    for (int i=heap.size()/2-1; i>=0; --i) {
        max_heapify(heap, i, heap.size());
    }

    return;
}

void heap_sort(vector<int>& v) {
    build_heap(v);
    int back = v.size()-1;
    while (back >= 0) {
        swap(v[0], v[back]);
        max_heapify(v, 0, back);
        back--;
    }

    cout << "After sorting: " ;
    for_each(v.begin(), v.end(), [](int& x) {cout << x << " ";});
    cout << endl;
}

int main() {
    vector<int> v{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap_sort(v);
}