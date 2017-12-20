//
// Created by Baocheng Han on 12/20/17.
//

#include "Solution.h"

int Solution::removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;

    int num = nums[0];

    for (int i = 1; i < nums.size();) {
        if (num == nums[i])
            nums.erase(nums.begin() + i );
        else {
            num = nums[i];
            i++;
        }
    }

    return nums.size();
}