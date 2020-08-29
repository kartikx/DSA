#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        char ch;
        int freq;
        Node* left;
        Node* right;
};

/**
 * Comp should return true, if l is supposed to go before r.
 * Elements which go before, appear at the bottom.
 * We want smaller freq. at top. Hence, return true for bigger.
 */
class comp {
    public:
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
};

Node* createNode(char ch, int freq, Node* left, Node* right) {
    Node* newNode = new Node();
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = left;
    newNode->right = right;
}

void encode(Node* root, string s, unordered_map<char, string>& huffmanCode) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = s;
    }

    encode(root->left, s + '0', huffmanCode);
    encode(root->right, s+'1', huffmanCode);
}



void buildHuffmanTree(string text) {

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto x : freq) {
        pq.push(createNode(x.first, x.second, NULL, NULL));
    }

    while (pq.size() > 1) {
        Node* top = pq.top(); pq.pop();
        Node* second_top = pq.top(); pq.pop();
        pq.push(createNode('\0', top->freq+second_top->freq, top, second_top));
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "",  huffmanCode);

    cout << "Huffman Codes are: " << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }

    string code("");
    for (char ch : text) {
        code += huffmanCode[ch];
    }

    cout << "Huffman Coding is: " << code << endl;
}

int main() {
    buildHuffmanTree("kartik");
}