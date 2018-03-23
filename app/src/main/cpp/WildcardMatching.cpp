//
// Created by bhan on 3/22/18.
//
#include "Solution.h"

bool isMatchSub(map<int, map<int, int>>& memo, string s, int i, string p, int j) {
    if(memo[i][j] != 0) {
        return memo[i][j] == 1 ? true : false;
    }

    if (i == s.size() && j == p.size()) {
        memo[i][j] = 1;
        return true;
    }

    if(j == p.size()){
        memo[i][j] = -1;
        return false;
    }

    if(i == s.size()) {
        if (p.at(j) == '*') {
            bool b = isMatchSub(memo, s, i, p, j + 1);
            memo[i][j] = b ? 1 : -1;
            return b;
        }
        else {
            memo[i][j] = -1;
            return false;
        }

    }

    if(p.at(j) == '?' || s.at(i) == p.at(j)) {
        bool b = isMatchSub(memo, s, i + 1, p, j + 1);
        memo[i][j] = b ? 1 : -1;
        return b;
    }

    if(p.at(j) == '*') {
        bool b = isMatchSub(memo, s, i, p, j + 1)
               || isMatchSub(memo, s, i + 1, p, j)
               || isMatchSub(memo, s, i + 1, p, j + 1);
        memo[i][j] = b ? 1 : -1;
        return b;
    }

    memo[i][j] = -1;
    return false;
}

bool Solution::isMatchWildcard(string s, string p) {
    map<int, map<int, int>> memo;
    return isMatchSub(memo, s, 0 , p , 0);
}
