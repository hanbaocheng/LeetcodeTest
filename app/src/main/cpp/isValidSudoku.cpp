//
// Created by bhan on 1/30/18.
//
#include "Solution.h"
static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

bool Solution::isValidSudoku(vector<vector<char>> &board) {
    map<int, int> horizon;
    map<int, int> vertical;
    map<int, int> grid;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            char p = board[i][j];
            if (p != '.') {
                int num = p - '0';
                int set = 1 << num;

                int hValue = horizon[i];
                if (hValue & set)
                    return false;
                else {
                    horizon[i] = hValue | set;
                }

                int vValue = vertical[j];
                if (vValue & set)
                    return false;
                else {
                    vertical[j] = vValue | set;
                }

                int gValue = grid[i / 3 * 3 + j / 3];
                if (gValue & set)
                    return false;
                else {
                    grid[i / 3 * 3 + j / 3] = gValue | set;
                }
            }
        }
    }
    return true;
}

void Solution::solveSudoku(vector<vector<char>> &board) {
    map<int, int> horizon;
    map<int, int> vertical;
    map<int, int> grid;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            char p = board[i][j];
            if (p != '.') {
                int num = p - '0';
                int set = 1 << num;

                int hValue = horizon[i];
                if (hValue & set)
                    return;
                else {
                    horizon[i] = hValue | set;
                }

                int vValue = vertical[j];
                if (vValue & set)
                    return;
                else {
                    vertical[j] = vValue | set;
                }

                int gValue = grid[i / 3 * 3 + j / 3];
                if (gValue & set)
                    return;
                else {
                    grid[i / 3 * 3 + j / 3] = gValue | set;
                }
            }
        }
    }

    int finish = false;
    while (!finish) {
        finish = true;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(i == 7 && j == 4)
                    finish = true;
                char p = board[i][j];
                if (p == '.') {
                    finish = false;
                    int hValue = horizon[i];
                    int vValue = vertical[j];
                    int gValue = grid[i / 3 * 3 + j / 3];

                    // sub 2 power of 0 as well
                    int value = 1024 - 1 - 1 - (hValue | vValue | gValue);

                    //there is only one number left
                    if ((value & value - 1) == 0) {

                        horizon[i] = hValue | value;
                        vertical[j] = vValue | value;
                        grid[i / 3 * 3 + j / 3] = gValue | value;

                        int power = 0;
                        while (value != 1) {
                            value = value / 2;
                            power++;
                        }

                        char ch = '0' + power;
                        //std::replace(board[i].begin()+j, board[i].begin()+j, '.', ch);
                        board[i][j] = ch;
                    }
                }
            }
        }
    }
}