//
// Created by bhan on 1/30/18.
//
#include "Solution.h"

static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();


int Solution::searchRotatedSortedArray(vector<int> &nums, int target) {
    int right = nums.size() - 1;
    int left = 0;

    if(nums.size() == 0)
        return -1;

    if(nums[0] > nums[nums.size() - 1]) {
        while (left < right) {
            int mid = (left + right) / 2;

            if(nums[left] == target)
                return  left;
            if (nums[right] == target)
                return right;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] == nums[left]) {
                break;
            } else if(nums[mid] > nums[left]) {
                left = mid;
            } else if(nums[mid] < nums[left]) {
                right = mid;
            }
        }
        if (target > nums[left]
            || target < nums[right]
            || (target < nums[0] && target > nums[nums.size() - 1]))
            return -1;

        if (target == nums[0]) {
            return 0;
        } else if (target > nums[0]) {
            right = left;
            left = 0;
        } else {
            left = right;
            right = nums.size() - 1;
        }
    }

    printf("%d--%d", left, right);
    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        }
    }

    return -1;
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    vector<int> ret = {-1,-1};

    if (nums.size() == 0)
        return ret;

    while (left <= right){
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            ret.clear();
            int i = mid;
            for (i = mid - 1; i >= 0 && target == nums[i]; --i);
            ret.push_back(i + 1);
            for (i = mid + 1; i < nums.size() && target == nums[i]; ++i);
            ret.push_back(i - 1);

            return ret;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ret;
}