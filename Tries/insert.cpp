#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        TrieNode() {
            this->children = vector<TrieNode*>(26, NULL);
            this->isEndOfWord = false;
        }
        vector<TrieNode*> children;
        bool isEndOfWord;
};

void insert(TrieNode* root, string& key) {
    if (!root) {
        return;
    }

    TrieNode* temp = root;

    for (int i=0; i<key.size(); i++) {
        int index = key[i]-'a';
        if (!temp->children[index])
            temp->children[index] = new TrieNode();
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool search(TrieNode* root, string& key) {
    TrieNode* temp = root;
    for (int i=0; i<key.size(); i++) {
        int index = key[i]-'a';
        if (!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }

    return temp && temp->isEndOfWord;
}

void printTrieUtil(TrieNode* root, string s) {
    for (int i=0; i<root->children.size(); i++) {
        if (root->children[i]) {
            char ch = 'a' + i;
            s.push_back(ch);
            printTrieUtil(root->children[i], s);
            s.pop_back();
        }
    }

    if (root->isEndOfWord) {
        cout << s << endl;
    }
}

void printTrie(TrieNode* root) {
    printTrieUtil(root, "");
}

int main() {
    vector<string> keys{"there", "their", "car", "cards", "alpha", "alp"};
    TrieNode* root = new TrieNode();

    for (auto str : keys) {
        insert(root, str);
    }

    printTrie(root);
}