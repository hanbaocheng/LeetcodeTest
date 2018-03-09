//
// Created by bhan on 1/15/18.
//

#include "Solution.h"
static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

void Solution::nextPermutation(vector<int> &nums) {
    int end = nums.size() - 1;
    if(end == 0)
        return;

    int i = 0;
    for (i = end; i > 0 ; --i) {
        if (nums[i] > nums[i - 1]) {
            break;
        }
    }

    for (int j = end; i > 0 && j >= i ; --j) {
        if (nums[j] > nums[i - 1]) {
            std::iter_swap(nums.begin() + j, nums.begin() + i - 1);
            break;
        }
    }

    sort(nums.begin() + i, nums.end());
}