//
// Created by bhan on 3/24/18.
//
#include "Solution.h"
void backtrace(vector<vector<string>>& all, int n, vector<string>& one, map<int, int>& coordinate ) {
    int start = coordinate.size();

    if (start == n){
        all.push_back(one);
        return;
    }

    int i = start;
    {
        string row;
        row.insert(row.begin(), n, '.');
        for (int j = 0; j < n; ++j) {
            bool attacked = false;
            for (const pair<int, int> item: coordinate) {
                if (i == item.first
                    || j == item.second
                    || (abs(item.first - i) == abs(item.second - j))) {
                    attacked = true;
                    break;
                }
            }
            if (attacked) continue;

            row[j] = 'Q';
            one.push_back(row);
            coordinate[i] = j;
            backtrace(all, n, one, coordinate);
            coordinate.erase(i);
            one.pop_back();
            row[j] = '.';

        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> all;
    vector<string> one;
    map<int, int> coordinate;
    backtrace(all, n, one, coordinate);

    return all;
}
