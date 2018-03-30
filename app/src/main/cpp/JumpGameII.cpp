//
// Created by bhan on 3/23/18.
//
#include "Solution.h"

int minjump(map<int, int>& memo, vector<int>& nums, int start) {
    if(memo.find(start) != memo.end()) {
        return memo[start];
    }

    int maxsteps = nums[start];

    if (start + maxsteps >= nums.size() - 1) {
        memo[start] = 1;
        return 1;
    }

    int min = nums.size() - 1 - start - 1;
    for (int i = 1; i <= maxsteps; ++i) {
        int nextmin = minjump(memo, nums, start + i);
        if (nextmin < min)
            min = nextmin;
    }

    memo[start] = min + 1;
    return min + 1;
}

int Solution::jump(vector<int> &nums) {
/*    map<int, int> memo;
    minjump(memo, nums, 0);
    return memo[0];*/

    int memo[30000] = {0};
    int lastindex = nums.size() - 1;
    int firstonejump = lastindex;
    for (int i = lastindex - 1; i >= 0 ; --i) {
        if(i + nums[i] >= lastindex) {
            memo[i] = 1;
            firstonejump = i;

        } else {
            int maxsteps = nums[i];
            int min = lastindex;
            for (int j = maxsteps; j > 0 ; --j) {
                if (i + j >= firstonejump) {
                    min = 1;
                    break;
                }
                if (memo[i + j] < min)
                    min = memo[i + j];
            }

            memo[i] = min + 1;
        }
    }

    return memo[0];
}
