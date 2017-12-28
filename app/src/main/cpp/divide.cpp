//
// Created by bhan on 12/22/17.
//
#include "Solution.h"

int Solution::divide(int dividend, int divisor) {
    int mydividend = dividend;
    int mydivisor = divisor;

    if (mydividend == INT32_MIN && mydivisor == -1) {
        return INT32_MAX;
    }

    if (mydividend == INT32_MIN && mydivisor == 1) {
        return INT32_MIN;
    }

    int ret = 0;
    bool sign = (mydividend & 0x80000000) ^ (mydivisor & 0x80000000);
    if (mydivisor < 0)
    {
        if (mydivisor == INT32_MIN) {
            if (mydividend == INT32_MIN)
                return 1;
            else return 0;
        }
        mydivisor = -1 * mydivisor;
    }


    if (mydividend < 0) {
        if (mydividend == INT32_MIN)
        {
            mydividend += mydivisor;
            ret++;
        }
        mydividend *= -1;
    }


    while (mydividend >= mydivisor) {

/*        for (int i = 0; (mydivisor << i) > 0 && mydividend >= (mydivisor << i); ++i) {
            ret += (1 << i);
            mydividend -= (mydivisor << i);
        }*/

        int quotient = -1;
        for (int i = 0; (mydivisor << i) > 0 && mydividend >= (mydivisor << i); ++i) {
            quotient = i;
        }

        if (quotient > -1) {
            ret += (1 << quotient);
            mydividend -= (mydivisor << quotient);
        }
    }

    return sign == 0 ? ret : -1 * ret;
}
int divide1(int dividend, int divisor) {
    int mydividend = dividend;
    int mydivisor = divisor;

    if (mydividend == INT32_MIN && mydivisor == -1) {
        return INT32_MAX;
    }

    if (mydividend == INT32_MIN && mydivisor == 1) {
        return INT32_MIN;
    }

    int ret = 0; bool sign = (mydividend & 0x80000000) ^ (mydivisor & 0x80000000);
    if (mydivisor < 0)
    {
        if (mydivisor == INT32_MIN) {
            if (mydividend == INT32_MIN)
                return 1;
            else return 0;
        }
        mydivisor = -1 * mydivisor;
    }


    if (mydividend < 0) {
        if (mydividend == INT32_MIN)
        {
            mydividend += mydivisor;
            ret++;
        }
        mydividend *= -1;
    }

    int factor = 1;
    int aDivisior = mydivisor * factor;
    while (aDivisior >= mydivisor && mydividend >= aDivisior) {
        mydividend -= aDivisior;
        ret += factor;
        factor++;
        aDivisior = mydivisor * factor;
    }

    do{
        factor--;
        aDivisior = mydivisor * factor;
        if(mydividend >=aDivisior) {
            mydividend -= aDivisior;
            ret += factor;
        }
    } while (mydividend > mydivisor);

    return sign == 0 ? ret : -1 * ret;
}
