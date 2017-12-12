//
// Created by bhan on 12/12/17.
//

#include "Solution.h"

static const auto ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

int Solution::reverseInteger(int x) {
    int one_tenth_max = 0x7FFFFFFF / 10;
    int max_mode = 0x7FFFFFFF % 10;
    int y = 0;
    while(x != 0) {
        bool signbit_y = y & 0x80000000;
        bool signbit_x = x & 0x80000000;
        int abs_y = y;
        int abs_x = x;
        if (signbit_y)  abs_y = -1 * abs_y;
        if (signbit_x)  abs_x = -1 * abs_x;
        if (abs_y > one_tenth_max ||
                (abs_y == one_tenth_max && abs_x % 10 > max_mode))
            return 0;
        y = y * 10 + x % 10;
        x = x / 10;
    }

    return y;
}

/*
int reverse(int x) {
    int max = 0x7FFFFFFF;
    int min = -1 * max;
    long long y = 0;
    while(x != 0) {
        y = y * 10 + x % 10;
        if(y > max || y < min) return 0;
        x = x / 10;
    }

    return (int)y;
}*/
