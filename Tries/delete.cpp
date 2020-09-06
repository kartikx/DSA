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

bool isLeaf(TrieNode* root) {
    if (!root) {
        return true;
    }

    for (auto x : root->children) {
        if (x)
            return false;
    }
    return true;
}

bool deleteKeyUtil(TrieNode* root, string& key, int charIndex) {
    // Base Case.
    if (charIndex >= key.length()-1) {
        if (isLeaf(root)) {
            delete root;
            return true;
        }
        else {
            if (root->isEndOfWord) {
                root->isEndOfWord = false;
                return false;
            }
        }
    }

    int index = key[charIndex]-'a';

    if (!root->children[index]) {
        return false;
    }

    if (deleteKeyUtil(root->children[index], key, charIndex+1)) {
        root->children[index] = NULL;
        if (isLeaf(root) && !root->isEndOfWord) {
            delete root;
            return true;
        }
    }

    return false;
}

void deleteKey(TrieNode* root, string& key) {
    if (!root) {
        return;
    }

    deleteKeyUtil(root, key, 0);
}


int main() {
    vector<string> keys{"there", "their", "car", "cards", "carbs", "alpha", "alp"};
    TrieNode* root = new TrieNode();

    for (auto str : keys) {
        insert(root, str);
    }

    printTrie(root);
    cout << "----" << endl;
    deleteKey(root, keys[3]);
    deleteKey(root, keys[4]);
    printTrie(root);
}