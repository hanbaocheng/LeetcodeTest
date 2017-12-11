//
// Created by Baocheng Han on 12/5/17.
//

#ifndef MEDIONFILEEXPLORER_ADDTWONUMBERS_H
#define MEDIONFILEEXPLORER_ADDTWONUMBERS_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

using std::vector;
using std::string;
using std::ios;
using std::cin;
using std::map;
using std::unordered_map;

class Solution {
private:

public:
    std::vector<int> twoSum(vector<int>& nums, int target);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    int lengthOfLongestSubstring(string s);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};


#endif //MEDIONFILEEXPLORER_ADDTWONUMBERS_H
