//
// Created by Baocheng Han on 12/7/17.
//

#include "AddTwoNumbers.h"
using std::vector;

static const auto ____  = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    return nullptr;
}();

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    unsigned long size1 = nums1.size();
    unsigned long size2 = nums2.size();
    vector<int> temp;
    if(size1 > size2){ temp = nums1; nums1 = nums2;
     nums2 = temp; size1 = nums1.size(); size2 = nums2.size();}
    long left = 0, right = size1 - 1;

    //The Kth big number, where K is equal to half of the two lengths.
    unsigned long K = (size1 + size2 + 1) / 2;
    long index1 = -1, index2 = K - (index1 + 1) - 1;

    double left_median, right_median;
    bool finding = true;
    if (size1 == 0) {
        left_median = nums2[K - 1];
        right_median = nums2[K];
        finding = false;
    }

    if (size2 == 0) {
        left_median = nums1[K - 1];
        right_median = nums1[K];
        finding = false;
    }

    while (finding/*left <= right && index2 > 0*/) {
        if (right == -1) index1 = -1;
        else index1 =  left +  (right - left) / 2;

        index2 = K - (index1 + 1) - 1;

        if (index1 < 0 || index2 + 1 == size2) {
            if (nums1[index1 + 1] >= nums2[index2]) {
                left_median = nums2[index2];
                right_median = nums1[index1 + 1];
                if (index1 >= 0 && nums1[index1] > left_median ) left_median = nums1[index1];
                if (index2 + 1 < size2 && nums2[index2 + 1] < right_median) right_median = nums2[index2 + 1];
                break;
            }
            else left = index1 + 1;
        }
        else if (index1 + 1 == size1 || index2 < 0) {
                if (nums1[index1] <= nums2[index2 + 1]) {
                    left_median = nums1[index1];
                    right_median = nums2[index2 + 1];
                    if (index2 >=0 && nums2[index2] > left_median) left_median = nums2[index2];
                    if (index1 + 1 < size1 && nums1[index1 + 1] < right_median) right_median = nums1[index1 + 1];
                    break;
                }
                else right = index1 - 1;
        } else if (nums1[index1 + 1] >= nums2[index2]) {
                if (nums2[index2 + 1] >= nums1[index1]) {
                    left_median = nums1[index1] > nums2[index2] ? nums1[index1] : nums2[index2];
                    right_median = nums1[index1 + 1] < nums2[index2 + 1] ? nums1[index1 + 1]: nums2[index2 + 1];
                    break;
                }
                else right = index1 - 1;
            }
        else left = index1 + 1;
    }

    if((size1 + size2) % 2 == 0 ) return (left_median + right_median) / 2;
    else return left_median;
}