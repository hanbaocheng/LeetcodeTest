//
// Created by Baocheng Han on 12/11/17.
//
#include "Solution.h"

static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

string Solution::zigzagConvert(string s, int numRows) {
    string zigzag;
    int unit = numRows + numRows - 2;
    if (numRows == 1) unit = 1;

    for (int i = 0; i < numRows; ++i) {
        int index = i;
        while (index < s.size()) {
            zigzag.push_back(s[index]);

            if(i > 0 && i < numRows - 1) {
                int zigzag_index = index / unit * unit + (unit - index % unit);
                if(zigzag_index < s.size())
                    zigzag.push_back(s[zigzag_index]);
            }

            index += unit;
        }
    }
    return zigzag;
}