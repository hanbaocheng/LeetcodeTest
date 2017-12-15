//
// Created by bhan on 12/15/17.
//

#include "Solution.h"

vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    map<int, vector<int>> value_to_index;
    vector<vector<int>> sets;

    for (int i = 0; i < nums.size(); ++i) {
        if (value_to_index.find(nums[i]) == value_to_index.end()) {
            vector<int> indices;
            indices.push_back(i);
            value_to_index[nums[i]] = indices;
        } else {
            value_to_index[nums[i]].push_back(i);
        }
    }

    for (int i = 0; i < nums.size() -1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int value = nums[i] + nums[j];
            value *= -1;
            if (value_to_index.find(value) != value_to_index.end()) {
                vector<int> indices = value_to_index[value];
                for (int k = 0; k < indices.size(); ++k) {
                    if (i != indices[k] && j != indices[k]) {
                        vector<int> set;
                        set.push_back(value);
                        set.push_back(nums[i]);
                        set.push_back(nums[j]);

                        sets.push_back(set);
                    }
                }
            }
        }
    }

    return sets;
}