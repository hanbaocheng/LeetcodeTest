//
// Created by bhan on 3/19/18.
//
#include "Solution.h"

int Solution::firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (i != nums[i] - 1)
            return i + 1;
    }

    return nums.size() + 1;
}
