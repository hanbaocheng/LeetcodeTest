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
static auto _____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

/*bool Solution::isMatch(string s, string p) {
    if (p.size() == 0)
        return s.size() == 0;

    if (p.size() >= 2 && p[1] == '*') {
        //p: "a*......" size >= 2
        //s: "", "a", "aa...." size >= 0
        if (s.size() == 0)
            return isMatch(s, p.substr(2));
        else if(s[0] == p[0] || p[0] == '.') {
            return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        } else if (s[0] != p[0]) {
            return isMatch(s, p.substr(2));
        }

    } else {
        //s: "", "a", "aa...." size >= 0
        //p: "a", "aa...." size > 1
        if (s.size() == 0)
            return false;
        else if (s[0] == p[0] || p[0] == '.') {
            return isMatch(s.substr(1), p.substr(1));
        }

    }
    return false;
}*/

int state[100][100] = {0};

bool dp(int i, int j, string s, string p) {
    if (state[i][j] != 0)
        return state [i][j] == 1 ? true : false;

    bool  ret = false;

    if (p.size() == j) {
        ret = (s.size() == i);
        ret == true ? state[i][j] = 1 : state[i][j] = -1;
        return ret;
    }

    if (p.size() - j >= 2 && p[j+1] == '*') {
        //p: "a*......" size >= 2
        //s: "", "a", "aa...." size >= 0
        if (s.size() == i)
            ret =  dp(i, j + 2, s, p);
        else if(s[i] == p[j] || p[j] == '.') {
            ret =  dp(i + 1, j, s, p) || dp(i, j + 2, s, p);
        } else if (s[i] != p[j]) {
            ret =  dp(i, j +2, s, p);
        }

    } else {
        //s: "", "a", "aa...." size >= 0
        //p: "a", "aa...." size > 1
        if (s.size() == i)
            ret = false;
        else if (s[i] == p[j] || p[j] == '.') {
            ret =  dp(i + 1, j + 1, s, p);
        }

    }
    ret == true ? state[i][j] = 1 : state[i][j] = -1;
    return ret;
}

/**
 * State transfer function
 * f(i, j) = (s[i] == p[i] || s[i] == '.') && ( p[j+1] == '*' && (F(i+1, j) || F(i, j+2)) || F(i+1, j+1) )
 *  (
 * F(i, j) = F(0, 0) && ...&& F(i-1, j-1) && f(i, j)
 *
 * @param s
 * @param p
 * @return
 */

bool Solution::isMatch(string s, string p) {
    state[100][100] = {0};
    dp( 0, 0, s, p);
    return state[s.size()][p.size()] == 1;
}