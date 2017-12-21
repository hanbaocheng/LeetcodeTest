//
// Created by bhan on 12/21/17.
//
#include "Solution.h"

void dp(int i , map<int, int>& overlay, string needle) {
    if (i == 0)
        overlay[i] = -1;

    if (needle[i] != needle[0])
    for (int i = 1; i < needle.size(); ++i) {
        if (needle[i] != needle[0] && needle[i] == needle[overlay[i - 1] + 1]) {
            overlay[i] = overlay[i - 1] + 1;
        } else if (needle[i] == needle[0]) {
            overlay[i] = 0;
        } else
            overlay[i] = -1;
    }
}

int Solution::strStr(string haystack, string needle) {
    map<int, int> overlay;

    overlay[0] = -1;
    for (int i = 1; i < needle.size(); ++i) {
        if (needle[i] != needle[0] && needle[i] == needle[overlay[i - 1] + 1]) {
            overlay[i] = overlay[i - 1] + 1;
        } else if (needle[i] == needle[0]) {
            overlay[i] = 0;
        } else
            overlay[i] = -1;
    }

    int i = 0, j = 0;
    int back = -1;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (overlay[j] > -1 && back == -1) {
                back = i;
            }
        } else {
            if (back != -1) {
                i = back + 1;
                back = -1;
            } else
                i++;
            int move = 0;//overlay[j - 1] + 1;
            j = move;
        }
    }

    return j == needle.size() ? i - j : -1;
}
