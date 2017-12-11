//
// Created by bhan on 12/11/17.
//
#include "Solution.h"

string Solution::longestPalindrome(string s) {
    unsigned long palindromeLength = 0;
    unsigned long start = 0;
    unsigned long size = s.size();

    for (int i = 0; i < size; ++i) {
        int left = i - 1, right = i + 1;
        int maxlen = 0;
        while (left >= 0 && right < size)
        {
            if(s[left] == s[right]) {
                left--;
                right++;
                maxlen += 2;

            } else {
                break;
            }
        }
        if (maxlen > palindromeLength) {
            palindromeLength = maxlen + 1;
            start = left + 1;
        }

        left = i, right = i + 1;
        maxlen = 0;
        while (left >= 0 && right < size)
        {
            if(s[left] == s[right]) {
                left--;
                right++;
                maxlen += 2;

            } else {
                break;
            }
        }
        if (maxlen > palindromeLength) {
            palindromeLength = maxlen;
            start = left + 1;
        }
    }
    return s.substr(start, palindromeLength);
}
