//
// Created by bhan on 3/22/18.
//

#include "Solution.h"
string Solution::multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
        return "0";

    int product[500] = {0};

    int size1 = num1.size();
    int size2 = num2.size();

    for (int i = size1 -1 ; i >= 0 ; --i) {
        int a = num1.at(i) - '0';

        for (int j = size2 - 1; j >= 0; --j) {
            int b = num2.at(j) - '0';
            product[size1 - 1 - i + size2 - 1 - j] += a * b;
        }
    }

    string ret;
    for (int i = 0; i < size1 - 1 + size2 - 1; ++i) {
        if (product[i] / 10 > 0) {
            product[i + 1] += product[i] / 10;
            product[i] = product[i] % 10;
            //ret.push_back('0' + product[i]);
        }
    }

    int last = product[size1 - 1 + size2 - 1];
    while (last) {
        ret.insert(ret.begin(), '0' + last % 10);
        last = last / 10;
    }

    for (int i = size1 - 1 + size2 - 1 - 1; i >= 0; --i) {
        ret.push_back('0' + product[i]);
    }

    return ret;
}