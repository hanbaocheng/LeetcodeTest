//
// Created by bhan on 12/15/17.
//
#include "Solution.h"

int Solution::maxArea(vector<int> &height) {
    int max = 0;
    int left = 0; int right = height.size() - 1;

    while (left < right) {
        int area = 0;

        if (height[left] < height[right]) {
            area = height[left] * (right - left);
            left++;
        } else {
            area = height[right] * (right - left);
            right--;
        }
        max = max < area ? area : max;
    }
    return max;
}