//
// Created by Baocheng Han on 12/7/17.
//

#include "AddTwoNumbers.h"
using std::vector;

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    struct MedianIndices {
        unsigned long left_index;
        unsigned long right_index;
        int left_median;
        int right_median;
    };

    auto getMedianIndices = [](vector<int> &nums,
                        long start, long end,
                        MedianIndices & indices) {
        long size = end - start + 1;
        indices.left_index = (size - 1) / 2;
        indices.right_index = size / 2;
        indices.left_median = nums[indices.left_index];
        indices.right_median = nums[indices.right_index];
    };

    auto getMedian = [](int left, int right) -> double {
        return (double(left + right)) / 2;
    };

    if (nums1.size() == 0)
        nums1 = nums2;
    if (nums2.size() == 0)
        nums2 = nums1;

    unsigned long start1 = 0, end1 = nums1.size() - 1;
    unsigned long start2 = 0, end2 = nums2.size() - 1;

    MedianIndices indices1, indices2;

    while (true) {
        getMedianIndices(nums1, start1, end1, indices1);
        getMedianIndices(nums2, start2, end2, indices2);

        if (indices1.right_median == indices2.right_median) {
            int max_left = (indices1.left_median > indices2.left_median)
                            ? indices1.left_median
                            : indices2.left_median;

            return getMedian(indices1.right_median, max_left);
        } else if (indices1.right_median > indices2.right_median) {
            if(indices1.left_median > indices2.right_median) {
                if (end1 == indices1.right_index ^
                    start2 == indices2.left_index) {
                    if (end1 == indices1.right_index)

                } else if (end1 == indices1.right_index &&
                           start2 == indices2.left_index) {
                    if (indices1.left_index != indices1.right_index ^
                        indices2.left_index != indices2.right_index) {
                        if (indices1.left_index == indices1.right_index)
                            return indices2.right_median;
                        if (indices2.left_index == indices2.right_index)
                            return indices1.left_median;
                    } else
                        return getMedian(indices1.left_median, indices2.right_median);
                }
                end1 = indices1.right_index;
                start2 = indices2.left_median;
            } else {
                int max_left = (indices1.left_median > indices2.left_median)
                               ? indices1.left_median
                               : indices2.left_median;

                return getMedian(indices2.right_median, max_left);
            }
        } else {
            if(indices1.right_median < indices2.left_median) {
                if (start1 == indices1.left_index &&
                        end2 == indices2.right_index) {
                    if (indices1.left_index != indices1.right_index ^
                        indices2.left_index != indices2.right_index) {
                        if (indices1.left_index == indices1.right_index)
                            return indices2.left_median;
                        if (indices2.left_index == indices2.right_index)
                            return indices1.right_median;
                    } else
                        return getMedian(indices2.left_median, indices1.right_median);
                }
                start1 = indices1.left_index;
                end2 = indices2.right_index;
            } else {
                int max_left = (indices1.left_median > indices2.left_median)
                               ? indices1.left_median
                               : indices2.left_median;
                return getMedian(indices1.right_median, max_left);
            }
        }
    }

}