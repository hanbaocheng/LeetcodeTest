//
// Created by bhan on 12/12/17.
//
#include "Solution.h"
static auto _____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

bool isPalindromeNumber(int left, int right) {
    if (left < right)
        return false;
    if (left == right)
        return true;
    if (left / 10 == right )
        return true;
    if (isPalindromeNumber(left / 10, (left % 10) + 10 * right))
        return true;

    return false;
}

bool Solution::isPalindrome(int x) {
    if(x < 0)
        return false;

    if(x > 0 && x % 10 == 0)
        return false;

    return isPalindromeNumber(x, 0);
}
