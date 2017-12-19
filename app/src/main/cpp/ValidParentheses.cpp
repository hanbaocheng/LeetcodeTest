//
// Created by bhan on 12/18/17.
//
#include "Solution.h"
static const auto _____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

bool isClosing(char bracket) {
    return bracket == ')' || bracket == ']' || bracket == '}';
}

bool isPair(char left, char right) {
    switch (left) {
        case '(':
            return right == ')';
        case '[':
            return right == ']';
        case '{':
            return right == '}';
    }
    return false;
}

bool Solution::isValidParentheses(string s) {
    stack<char> bracket;
    for (int i = 0; i < s.size(); ++i) {
        if(bracket.size() > s.size() - 1 - i )
            return false;
        char top = ' ';
        if (bracket.size() > 0)
            top = bracket.top();
        if (isClosing(s[i]) && isPair(top, s[i])) {
            bracket.pop();
        } else {
            bracket.push(s[i]);
        }
    }

    return bracket.size() == 0;
}


void dp(string candidate, int sum, int unpaired, int n, vector<string>& ret) {
    if(sum < 0 || sum > unpaired )
        return;
    if (unpaired == 0) {
        ret.push_back(candidate);
        return;
    }

    dp(candidate + "(", sum + 1, unpaired, n, ret);
    dp(candidate + ")", sum - 1, unpaired - 1, n, ret);

}
vector<string> Solution::generateParenthesis(int n) {
    vector<string> ret;
    dp("", 0, n, n, ret);
    return ret;
}