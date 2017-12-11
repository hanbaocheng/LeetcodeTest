//
// Created by bhan on 12/5/17.
//
#include "Solution.h"
#include <map>
#include <iostream>

static const auto disable_sync = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

    vector<int> Solution::twoSum(vector<int>& nums, int target) {
        vector<int> *ret  = new vector<int>();

        /**
         * brute force
         */
/*        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ret->push_back(i);
                    ret->push_back(j);
                    return *ret;
                }
            }
        }*/

        // map<value to indices>, consider there are
        // repeating values in vector<int> nums
/*        std::map<int, vector<int>*> valueMap;
        for (int i = 0; i < nums.size(); ++i) {
            int value = nums[i];
            if (valueMap[value] == nullptr) {
                vector<int> *indices = new vector<int>();
                indices->push_back(i);
                valueMap[value] = indices;
            } else {
                vector<int> *indices = valueMap[value];
                indices->push_back(i);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            int var1 = nums[i];
            int var2 = target - var1;
            vector<int > *indices = valueMap[var2];

            if (indices != nullptr &&
                    (indices->at(0) != i || indices->size() == 2)){
                int key = indices->at(indices->size() == 1 ? 0 : 1);

                ret->push_back(i);
                ret->push_back(key);
                return *ret;
            }
        }*/

        std::map<int, int> valueMap;
        for (int i = 0; i < nums.size(); ++i) {
            int value = nums[i];
            int index1 = -1;
            if (valueMap.find(value) != valueMap.end())
                index1 = valueMap[value];
            valueMap[value] = i;

            int var1 = nums[i];
            int var2 = target - var1;

            if (valueMap.find(var2) != valueMap.end()){
                int index2 = valueMap[var2];
                // Found itself and there is only one
                if (index2 == i && index1 == -1) continue;

                if (index1 == -1) index1 = index2;

                index2 = i;

                ret->push_back(index1);
                ret->push_back(index2);

                return *ret;
            }
        }
        return *ret;
    }
