#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int r, int c)
{
    if (x >= r || y >= c || x < 0 || y < 0)
        return false;
    return true;   
}

int countLiveNeighbours(vector<vector<int>>& board, int i, int j)
{
    vector<int> moveX = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> moveY = {-1, 0, 1, -1, 1, -1, 0, 1};
    int count = 0;
    for (int k=0; k<8; k++) {
        int nextX = i + moveX[k];
        int nextY = j + moveY[k];
        
        if (isValid(nextX, nextY, board.size(), board[i].size()) && board[nextX][nextY] == 1)
            count++; 
    }
    return count;
}

void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> output(board);

    for (int i=0; i<board.size(); ++i) {
        for (int j=0; j<board[i].size(); ++j){
            int count = countLiveNeighbours(board, i, j);
            if (board[i][j] == 1 && (count != 2 && count != 3))
            {
                cout << count << endl;
                output[i][j] = 0;
            }
            else if (board[i][j] == 0 && count == 3)
                output[i][j] =1 ;
        }
    }

    for (int i=0; i<board.size(); ++i) {
        for (int j=0; j<board[i].size(); ++j){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0},
                                 {0,0,1},
                                 {1,1,1},
                                 {0,0,0}};
    gameOfLife(board);
}