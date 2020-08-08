#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    Start off with a prospective list of Celeb.s, start iterating
    among known people for everyone, if there's someone they don't know
    remove that person from the list.
    O(N*2), 0(N)
*/

int getCelebUsingSet(vector<vector<int>>& knows) {
    unordered_set<int> celebs;

    for (int i=0;i<knows.size(); ++i) {
        celebs.insert(i);
    }

    for (int i=0; i<knows.size() ; ++i) {
        for (int j=0; j <knows[i].size(); ++j){
            if (celebs.empty()) {
                return -1;
            }
            if (knows[i][j] == 1) {
                celebs.erase(i);
            }
            if (knows[i][j] == 0 && i!=j) {
                celebs.erase(j);
            }
        }
    }

    if (celebs.size() > 1) {
        cout << "Something's wrong\n" ;
        return -1;
    }

    return *celebs.begin();
}

/*
    Iterate along the column for all columns.
    Find a column which has only 1 zero.
    This row might represent the celeb.
    Once you find such a column, the answer is 
    either the row corresponding to the 0 in that column,
    or it is -1. Because everyone knows the 0 in that column,
    hence there can't be any other celeb. as he's not allowed
    to know anyone.
    o(N*2), O(1).
*/
int getCelebIterate(vector<vector<int>>& knows)
{
    for (int i=0; i<knows.size(); i++) {
        int count0 = 0, pos0 = -1;
    
        // row iteration
        for (int j=0; j<knows.size(); j++) {
            if (knows[j][i] == 0) {
                count0++;
                pos0 = j;
                if (count0 > 1)
                    break;
            }
        }

        if (count0 == 1 && pos0 != -1) {
            for (int j=0; j<knows.size(); j++) {
                if (knows[pos0][j] == 1)
                    return -1;
            }
            return pos0;
        }
    }
    return -1;
}


/*
A graph based solution can be to iterate over
knows to get the indegree and outdegree for each person
in O(N*2) time, then iterate over the indegree and outdegree
simult. to find the person with indeg N-1 and outdeg 0.
O(N*2), O(1)
*/
int getCelebGraph(vector<vector<int>>& knows)
{
    return -1;
}

/*
Using Recursion,

Find celeb(k)
celeb(k+1) is either celeb(k) or k+1
if celeb(k) knows k+1 and k+1 doesn't know celeb(k) then k *may* be the celeb. 
May be because the rest of the elements may not know k+1. However this get's fixed 
in later recursive calls, because eventually there will be someone that everyone knows.
Try for yourself.
otherwise celeb(k) is the celeb(k+1).
*/


/*
An optimized approach
*/

int findCeleb(vector<vector<int>> knows)
{
    /*
    Starting from the first person, iterate through the people it knows.
    If it knows anyone, it won't be the celeb.
    The person it knows may be the celeb, so start iterating through that person
    instead. We don't need to consider the earlier elements in the row for this
    new person, because we can be sure that those are all 0s. Otherwise we would
    have reached this person earlier.
    Also we'll only go down the matrix this way. So it's kind of a scan from
    Top Left to Bottom Right.
    */

   /*
   Instead of thinking from a matrix point of view,
   it may also help to instead imagine an actual party, where
   you're going around asking people.
   */
   int candidate = 0;

   for (int i=0; i<knows.size() ;i++) {
       if (knows[candidate][i] == 1)
        candidate = i;
   }

   for (int i=0; i<knows.size() ;i++) {
       if (i != candidate && (knows[candidate][i] == 1 || knows[i][candidate] == 0))
        return -1;
   }

   return candidate;
}

int main() {
    vector<vector<int>> knows{ {0, 1, 1, 0},
                               {0, 0, 0, 0},
                               {0, 0, 1, 0},
                               {0, 1, 1, 0} };
    cout << getCelebIterate(knows) << endl;
}