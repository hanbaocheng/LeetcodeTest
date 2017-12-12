//
// Created by bhan on 12/12/17.
//

#include "Solution.h"

static auto _____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

int Solution::myAtoi(string str) {
    long long ret = 0;
    if (str.size() == 0)
        return 0;

    int start = 0;
    int signbit = 1;
    while (true) {
        if (str[start] == ' ') {
            start++;
        } else if (str[start] == '-' || str[start] == '+') {
            if (str[start] == '-')
                signbit = -1;
            start++;
            break;
        } else break;
    }

    while(start < str.size()) {
        char last = str[start];
        if(last >= '0' && last <= '9') {
            ret = ret * 10 + last - '0';
            if (signbit == -1 && ret - 1 > INT32_MAX) {
                return INT32_MIN;
            } else if (signbit == 1 && ret > INT32_MAX) {
                return INT32_MAX;
            }
        } else break;

        start++;
    }

    return signbit * ret;
}