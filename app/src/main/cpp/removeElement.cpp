//
// Created by bhan on 12/21/17.
//
#include "Solution.h"

auto const static ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

int Solution::removeElement(vector<int> &nums, int val) {
    int newlength = 0;

    for (int i = 0; i < nums.size() ; ++i) {
        if (nums[i] != val) {
            nums[newlength++] = nums[i];
        }
    }

    return newlength;
/*    if (nums[nums.size() - 1] != val)
        nums[newlength++] = nums[nums.size() - 1];*/
}
