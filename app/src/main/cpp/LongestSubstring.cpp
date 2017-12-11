//
// Created by bhan on 12/6/17.
//

#include "Solution.h"

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 *
 *  Given "abcabcbb", the answer is "abc", which the length is 3.
 *  Given "bbbbb", the answer is "b", with the length of 1.
 *  Given "pwwkew", the answer is "wke", with the length of 3.
 *
 *  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * @param s
 * @return
 */
static const auto ______ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();


/*int Solution::lengthOfLongestSubstring(string s) {
    int start;
    int end;
    int max = 0;
    unordered_map<char,int> substrmap;

    start = end = 0;
    while(start < s.size() && end < s.size()) {
        char current = s[end];
        //found char in substring
        if (substrmap.find(current) != substrmap.end()) {
            int index = substrmap[current];
            while (index >= 0 && start <= index) {
                substrmap.erase(s[start]);
                start++;
            }
        }
        substrmap[current] = end;
        end = end + 1;

        if (end - start > max) max = end - start;
    }
    return max;
}*/

int Solution::lengthOfLongestSubstring(string s) {
    string substring;
    string longestsubstring = substring;


    for (int i = 0; i < s.size(); ++i) {
        /**
         * here we need to optimize performance to traverse substring
         * instead of using find function which has O(n) Time complexity,
         * we need something with O(1) time complexity.
         */

        int index = substring.find(s[i], 0);
        if (index == string::npos) {
            substring.push_back(s[i]);
        } else {
            substring = substring.substr(index + 1);
            substring.push_back(s[i]);
        }

        if (substring.size() > longestsubstring.size()) {
            longestsubstring = substring;
        }
    }
    return longestsubstring.size();
}
