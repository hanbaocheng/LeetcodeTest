//
// Created by bhan on 12/12/17.
//
#include "Solution.h"
/**
 *    '.' Matches any single character.
 *    '*' Matches zero or more of the preceding element.

        The matching should cover the entire input string (not partial).

        The function prototype should be:
        bool isMatch(const char *s, const char *p)

        Some examples:
        isMatch("aa","a") → false
        isMatch("aa","aa") → true
        isMatch("aaa","aa") → false
        isMatch("aa", "a*") → true
        isMatch("aa", ".*") → true
        isMatch("ab", ".*") → true
        isMatch("aab", "c*a*b") → true
 * @param s
 * @param p
 * @return
 */
bool Solution::isMatch(string s, string p) {
    stack<char> stack1;
    stack<char> stack2;

    int size = s.size();

    for (int i = 0; i < p.size(); ++i) {
        stack1.push(p[i]);
    }

    int index = size - 1;
    while (stack1.size() > 0 && index >= 0) {
        char top = stack1.top();
        if(top == '*')
            return true;
        if(top == '.' || top == s[index]) {
            stack1.pop();
            index -= 1;
        }
    }

    return false;
}