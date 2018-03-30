//
// Created by bhan on 3/24/18.
//
#include "Solution.h"

void Solution::rotate(vector<vector<int>> &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
