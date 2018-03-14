//
// Created by Baocheng Han on 3/13/18.
//
#include "Solution.h"

static const auto ______ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

string Solution::countAndSay(int n) {
    if (n == 0)
        return nullptr;

    if (n == 1)
        return "1";

    string lastsay = countAndSay(n - 1);

    string ret = "";

    char ch = lastsay[0];
    int count = 1;
    for (int i = 1; i < lastsay.size(); ++i) {
        if (ch == lastsay[i]) {
            count++;
        } else {
            ret.append(1, count + '0');
            ret.append(1, ch);

            ch = lastsay[i];
            count = 1;
        }
    }

    ret.append(1, count + '0');
    ret.append(1, ch);

    return ret;
}
