//
// Created by bhan on 12/15/17.
//

#include "Solution.h"

string Solution::longestCommonPrefix(vector<string> &strs) {
    string prefix;

    if (strs.size() == 0)
        return prefix;

    prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int index1 = 0, index2 = 0;
        while (index1 < prefix.size() &&
               index2 < strs[i].size() &&
               prefix[index1] == strs[i][index2]) {
            index1++;
            index2++;
        }
        prefix = prefix.substr(0, index1);
        if (index1 == 0) break;

    }
    return prefix;
}