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

void findCombination(vector<vector<int>> &ret, map<int, int>& candidates, vector<int>& path, int target, int start){
    if (target < 0)
        return;

    if(target == 0) {
        ret.push_back(path);
    }

    for (std::pair<const int, int> &item: candidates) {
        if(item.first < start)
            continue;

        if (item.second == 0)
            continue;

        int next = target - item.first;

        item.second = item.second - 1;
        path.push_back(item.first);
        findCombination(ret, candidates, path, next, item.first);
        path.pop_back();
        item.second = item.second + 1;
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ret;
    map<int, int> candimap;
    for (int item: candidates) {
        if (candimap.find(item) != candimap.end()) {
            candimap[item] += 1;
        } else {
            candimap[item] = 1;
        }
    }

    vector<int> path;
    findCombination(ret, candimap, path, target, 0);
    return ret;
}