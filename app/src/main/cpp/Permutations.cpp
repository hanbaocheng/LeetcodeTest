//
// Created by bhan on 3/23/18.
//
#include "Solution.h"
void dopermute(vector<int>& nums, vector<vector<int>>& all, map<int, int>& counts, vector<int>& one){
    int size = nums.size();

    if (size == 0) {
        all.push_back(one);
        return;
    }

    map<int, int> dups;

    for (int i = 0; i < size; ++i) {
        int node = nums[i];
        if(dups[node] == 1)
            continue;
        dups[node] = 1;
        vector<int>::iterator del = nums.erase(nums.begin() + i);
        one.push_back(node);
        dopermute(nums, all, counts, one);
        one.pop_back();
        nums.insert(del, node);
    }
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> solutions;
    vector<int> one;
    map<int, int> counts;
    for (int i = 0; i < nums.size(); ++i) {
        counts[nums[i]] += 1;
    }

    dopermute(nums, solutions, counts, one);

    return  solutions;
}
