//
// Created by Baocheng Han on 12/5/17.
//

#ifndef MEDIONFILEEXPLORER_ADDTWONUMBERS_H
#define MEDIONFILEEXPLORER_ADDTWONUMBERS_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <map>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

using std::vector;
using std::stack;
using std::string;
using std::ios;
using std::cin;
using std::map;
using std::unordered_map;
using std::runtime_error;
using std::sort;

class Solution {
public:
    ListNode* getList(vector<int> list);
public:
    std::vector<int> twoSum(vector<int>& nums, int target);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    int lengthOfLongestSubstring(string s);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    string longestPalindrome(string s);
    string zigzagConvert(string s, int numRows);
    int reverseInteger(int x);
    int myAtoi(string str);
    bool isPalindrome(int x);
    bool isMatch(string s, string p);
    int maxArea(vector<int>& height);
    string intToRoman(int num);
    int romanToInt(string s);
    string longestCommonPrefix(vector<string>& strs);
    vector<vector<int>> threeSum(vector<int>& nums);
    int threeSumClosest(vector<int>& nums, int target);
    vector<string> letterCombinations(string digits);
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    ListNode* removeNthFromEnd(ListNode* head, int n);
    bool isValidParentheses(string s);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    vector<string> generateParenthesis(int n);
    ListNode* mergeKLists(vector<ListNode*>& lists);
    ListNode* swapPairs(ListNode* head);
    ListNode* reverseKGroup(ListNode* head, int k);
    int removeDuplicates(vector<int>& nums);
    int removeElement(vector<int>& nums, int val);
    int strStr(string haystack, string needle);
};


#endif //MEDIONFILEEXPLORER_ADDTWONUMBERS_H
