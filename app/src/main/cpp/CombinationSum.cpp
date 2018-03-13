//
// Created by Baocheng Han on 3/13/18.
//
#include "Solution.h"

bool findCombination(vector<vector<int>> &ret, set<int>& candidates, int target){

    for (int i = target; i > 0 ; i--) {
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
    set<int> candiset;
    for(int item: candidates){
        candiset.insert(item);
    }

    map<int, vector<int>> memo;
    vector<vector<int>> ret;

    for (int i = 1; i <= target; ++i) {
        int a = i;
        int b = target - i;
        if (a == 0 || b == 0)
    }
    return ret;
}