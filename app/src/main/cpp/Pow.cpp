//
// Created by bhan on 3/24/18.
//
#include "Solution.h"
double Solution::myPow(double x, int n) {
    double ret = 1;
    long long num = n;
    if (num == 0) {
        return ret;
    } else if(num > 0) {
        map<int, double > memo;
        memo[1] = x;
        while(num > 0) {
            double temp = x;
            long long j = 0;
            int tempn = num;
            for (j = 2; j <= tempn; j = j * 2) {
                if (memo.find(j) == memo.end()) {
                    temp = temp * temp;
                    memo[j] = temp;
                }
            }


            num = num - j / 2;
            ret = ret * memo[j/2];
            //if (ret < 0.0001)
            //    return 0;
        }
    } else {
        num = num * -1;
        map<int, double > memo;
        memo[1] = x;
        while(num > 0) {
            double temp = x;
            long long j = 0;
            int tempn = num;
            for (j = 2; j <= tempn; j = j * 2) {
                if (memo.find(j) == memo.end()) {
                    temp = temp * temp;
                    memo[j] = temp;
                }
            }


            num = num - j / 2;
            ret = ret * memo[j/2];
        }

        ret = 1.000000 / ret;
    }
    return ret;
}
