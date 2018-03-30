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
#include <set>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x=0) : val(x), next(nullptr) {}
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
using std::set;
using std::reverse;
using std::swap;
using std::pair;

class Solution {
public:
    ListNode* getList(vector<int> list);
public:
    //Sort method
    void bubble_sort(vector<int>& list);
    void insertion_sort(vector<int>& list);
    void selection_sort(vector<int>& list);
    void merge_sort(vector<int>& list);
    void quick_sort(vector<int>& list);

    //Google:
    // Bus line
    vector<int> findBestBusline(vector<vector<int>>& buslines, int start, int end);
    string decompressStr(string s);
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
    int divide(int dividend, int divisor);
    vector<int> findSubstring(string s, vector<string>& words);
    void nextPermutation(vector<int>& nums);
    int longestValidParentheses(string s);
    int searchRotatedSortedArray(vector<int>& nums, int target);
    vector<int> searchRange(vector<int>& nums, int target);
    bool isValidSudoku(vector<vector<char>>& board);
    void solveSudoku(vector<vector<char>>& board);
    string countAndSay(int n);
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);
    int firstMissingPositive(vector<int>& nums);
    int trap(vector<int>& height);
    string multiply(string num1, string num2);
    bool isMatchWildcard(string s, string p);
    int jump(vector<int>& nums);
    vector<vector<int>> permute(vector<int>& nums);
    void rotate(vector<vector<int>>& matrix);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    double myPow(double x, int n);
    vector<vector<string>> solveNQueens(int n);
};


#endif //MEDIONFILEEXPLORER_ADDTWONUMBERS_H
