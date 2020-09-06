#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node(int val) {
            this->val = val;
        }
        int val;
        Node* next;
};

Node* makeList(vector<int>& values) {
    Node* head = NULL;
    Node* curr = NULL;
    for (auto x : values) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            curr = head;
        }
        else {
            curr->next = newNode;
            curr = curr->next;    
        }
    }
    return head;
}

// Time Complexity: O(N). Space Complexity O(N).
int findUtil(Node*& head, int k, int& count) {
    if (!head) {
        count++;
        return -1;
    }

    int ans = findUtil(head->next, k, count);
    if (count == k) {
        // To prevent any more matches.
        count++;
        return head->val;
    }

    count++;
    return ans;
}

int findNthFromEnd(Node*& head, int k) {
    int count = 0;
    return findUtil(head, k, count);
}

int findNthFromEndIter(Node*& head, int k) {
    Node* slow = head;
    Node* fast = head;
    int i;
    for (i=1; fast != NULL && i<=k; i++){
        fast = fast->next;
    }

    if (i != k+1) {
        return -1;
    }

    while (fast) {
       slow = slow->next;
       fast = fast->next; 
    }

    return slow->val;
}

int main() {
    vector<int> values = {2, 4, 7, 1, 8 ,9};
    Node* head = makeList(values);
    for (int i=1; i<=values.size(); ++i) {
        cout << findNthFromEndIter(head, i) << endl;
    }
}