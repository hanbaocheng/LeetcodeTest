//
// Created by bhan on 12/22/17.
//
#include "Solution.h"

int Solution::divide(int dividend, int divisor) {
    if (dividend == INT32_MIN && divisor == -1) {
        return INT32_MAX;
    }

    if (dividend == INT32_MIN && divisor == 1) {
        return INT32_MIN;
    }

    int ret = 0; bool flag = (dividend & 0x80000000) ^ (divisor & 0x80000000);
    if (divisor < 0)
    {
        if (divisor == INT32_MIN) {
            if (dividend == INT32_MIN)
                return 1;
            else return 0;
        }
        divisor *= -1;
    }


    if (dividend < 0) {
        if (dividend == INT32_MIN)
        {
            dividend += divisor;
            ret++;
        }
        dividend *= -1;
    }

    int factor = 1;
    int aDivisior = divisor * factor;
    while (dividend > aDivisior) {
        dividend -= aDivisior;
        ret += factor;
        factor++;
        aDivisior = divisor * factor;
    }

    do{
        factor--;
        aDivisior = divisor * factor;
        if(dividend >=aDivisior) {
            dividend -= aDivisior;
            ret += factor;
        }
    } while (dividend > divisor);

    return flag == 0 ? ret : -1 * ret;
}
