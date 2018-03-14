//
// Created by Baocheng Han on 3/13/18.
//
#include "Solution.h"
/**
 *  For example, given candidate set [2, 3, 6, 7] and target 7,
        A solution set is:

        [
          [7],
          [2, 2, 3]
        ]

 * @param candidates
 * @param target
 * @return
 */

void findCombination(vector<vector<int>> &ret, set<int>& candidates, vector<int>& path, int target, int start){
    if (target < 0)
        return;

    if(target == 0) {
        ret.push_back(path);
    }

    for (const int &item: candidates) {
        if(item < start)
            continue;
        int next = target - item;

        path.push_back(item);
        findCombination(ret, candidates, path, next, item);
        path.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ret;
    set<int> candiset;
    for (int item: candidates) {
        candiset.insert(item);
    }

    vector<int> path;
    findCombination(ret, candiset, path, target, 0);
    return ret;
}