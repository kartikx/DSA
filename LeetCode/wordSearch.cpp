#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int r, int c){
    if (x >= r || y >= c || x < 0 || y < 0)
        return false;
    return true;
}

bool createWordUtil(vector<vector<char>>& board, string word, int& index, pair<int, int> position, map<pair<int, int>, int>& visited)
{
    if (index >= word.size()){
        return true;
    }
    // cout << (board[position.first][position.second]) << endl;
    vector<int> moveX = {-1, 1, 0, 0};
    vector<int> moveY = {0, 0, -1, 1};
    bool wordFound = false;
    for (int i=0; i<4; i++){
        int newX = position.first + moveX[i];
        int newY = position.second + moveY[i];

        if (!wordFound && isValid(newX, newY, board.size(), board[0].size()) &&
            board[newX][newY] == word[index] &&
            visited[{newX, newY}] == 0)
        {
            visited[{newX, newY}] = 1;
            index++;
            wordFound = createWordUtil(board, word, index, {newX, newY}, visited);
        }
    }
    // as you return from this, set visited false.
    visited[{position.first, position.second}] = 0;
    
    return wordFound;
}
bool exist(vector<vector<char>>& board, string word) {
    // If i use a visited, i need to make sure that they don't overlap
    // between different words, I think using a DFS would be better.
    // first store starting location into a queue
    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[i].size(); j++){
            if (board[i][j] == word[0]){
                // can i put this outside?
                map<pair<int, int>, int> visited;
                visited[{i, j}] = 1;
                int index = 1;
                if (createWordUtil(board, word, index, {i, j}, visited))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board {
                        {'A','B','C','E'},
                        {'S','F','C','S'},
                        {'A','D','E','E'}};
    cout << exist(board, "SEE");
}