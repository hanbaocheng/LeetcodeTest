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

int Solution::longestValidParentheses(string s) {
    vector<char> stack1;
    vector<int> indices;
    indices.push_back(0);

    int maxlen = 0;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];

        if(stack1.size() == 0 || ch == '(') {
            stack1.push_back(ch);
            indices.push_back(i);
            continue;
        }

        if (ch == ')') {
            if (stack1.size() != 0 && stack1[stack1.size() - 1] == '(') {
                stack1.pop_back();
                indices.pop_back();
                continue;
            } else {
                stack1.push_back(ch);
                indices.push_back(i);
            }
        }
    }

    indices.push_back(s.size());


    for (int i = 0; i < indices.size() - 1; ++i) {
        int len = indices[i+1] - indices[i] - 1;
        if (len > maxlen)
            maxlen = len;
    }
    return maxlen;
}

