//
// Created by bhan on 12/15/17.
//

#include "Solution.h"
auto const static ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    vector<vector<int>> sets;
/*    map<int, int> value_to_index;

    for (int i = 0; i < nums.size(); ++i) {
        int key = nums[i];
        ++value_to_index[key];
    }

    vector<int> sorted_nums;
    for (auto const& item: value_to_index) {
        for (int i = 0; i < item.second; ++i) {
            sorted_nums.push_back(item.first);
        }
    }*/

    sort(nums.begin(), nums.end());
    vector<int>& sorted_nums = nums;

    int size = sorted_nums.size();
    map<int, map<int, int>> mapout;
    for (int i = 0; size > 2 && i < size - 2; ++i) {
        int a = sorted_nums[i];
        int start = i + 1;
        int end = size - 1;

        while (start < end) {
            int b = sorted_nums[start];
            int c = sorted_nums[end];
            int sum = a + b + c;
            if(sum == 0) {
                end -= 1;
                map<int, int>& out = mapout[a];
                if (out.find(b) != out.end())
                    continue;

                out[b] = c;
                vector<int> set;
                set.push_back(a);
                set.push_back(b);
                set.push_back(c);

                sets.push_back(set);
            } else if(sum > 0)
                end -= 1;
            else
                start += 1;
        }
    }
    return sets;
}

int Solution::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int>& sorted_nums = nums;

    int size = sorted_nums.size();
    if (size < 3)
        return 0;
    int right = 0x7FFFFFFF;
    int left = -1 * right - 1;

    for (int i = 0; size > 2 && i < size - 2; ++i) {
        int a = sorted_nums[i];
        int start = i + 1;
        int end = size - 1;

        while (start < end) {
            int b = sorted_nums[start];
            int c = sorted_nums[end];
            int sum = a + b + c;
            int distance = sum - target;

            if(distance == 0)
                return target;
            else if (distance > 0) {
                --end;
                if (sum < right)
                    right = sum;
            } else {
                ++start;
                if (sum > left)
                    left = sum;
            }
        }
    }

    if (right == 0x7FFFFFFF)
        return left;
    if (left == -1 * 0x7FFFFFFF - 1)
        return right;

    return (right - target < target - left) ? right : left;
}
