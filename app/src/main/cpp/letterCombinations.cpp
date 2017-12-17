//
// Created by Baocheng Han on 12/17/17.
//

#include "Solution.h"

static auto const ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

static const map<char, string> digitsToChar = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
};

void dp(int start, string digits, vector<string>& ret){
    if(start == digits.size())
        return;

    char num = digits[start];
    string chars = digitsToChar.at(num);

    vector<string> all;
    for (int i = 0; i < chars.size() - 1; ++i) {
        vector<string> _new(ret);
        for (auto& item: _new) {
            item.push_back(chars[i]);
        }
        all.insert(all.end(), _new.begin(), _new.end());
    }

    for (auto& item: ret) {
        item.push_back(chars[chars.size() - 1]);
    }
    ret.insert(ret.end(), all.begin(), all.end());

    dp(++start, digits, ret);
}

vector<string> Solution::letterCombinations(string digits) {
    vector<string> ret;

    if (digits.size() == 0)
        return ret;
    char num = digits[0];
    string chars = digitsToChar.at(num);
    for (int i = 0; i < chars.size(); ++i) {
        string s;
        s.push_back(chars[i]);
        ret.push_back(s);
    }

    dp(1, digits, ret);
    return ret;
}
