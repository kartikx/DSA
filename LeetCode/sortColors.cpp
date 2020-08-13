#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& colors)
{
    int red = 0, blue = colors.size() - 1;
    int i=0;
    while (i < blue) {
        if (colors[i] == 0) {
            swap(colors[i], colors[red]);
            // I can be sure that the new number at red is 0, so increment red.
            red++;
            // Now i wouldn't want the 0 at position i to now get swapped with the red in front, so increment i.
            i++;
        }
        else if (colors[i] == 1) {
            i++;
        }
        else {
            swap(colors[i], colors[blue]);
            // When I swap with blue, i can be sure the new number at the blue is 2, so decrement it.
            blue--;
            // However you shouldn't increment I, because the new number at i may be 2, you can't skip it.
        }
    }
}

int main() {
    unordered_map<int, int> m;
    m[1] = 2;
    m.erase(1);
}