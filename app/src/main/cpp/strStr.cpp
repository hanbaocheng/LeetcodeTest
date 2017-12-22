//
// Created by bhan on 12/21/17.
//
#include "Solution.h"
auto const static ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

/**
 * there are KMP, BM and Sunday algorithm, here Sunday algorithm is used
 * @param haystack
 * @param needle
 * @return
 */
int Solution::strStr(string haystack, string needle) {
    int pSize = needle.size();

    int i = 0, j = 0;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++; j++;
        } else {
            int newPos = i - j + pSize;
            char nCh = haystack[newPos];
            size_t nPos= needle.rfind(nCh);
            if (nPos != string::npos) {
                i = newPos - nPos;
                j = 0;
            } else {
                i = newPos;
                j = 0;
            }
        }
    }

    return j == pSize ? i - j : -1;
}
