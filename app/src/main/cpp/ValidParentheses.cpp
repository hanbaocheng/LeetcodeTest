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

void dp(char start, int n, vector<string>& ret){

}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> ret;
    for (int i = n -1; i >= 0; --i) {
        
    }

    return ret;
}