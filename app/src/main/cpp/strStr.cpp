//
// Created by bhan on 12/21/17.
//
#include "Solution.h"
auto const static ____ = [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

/**
 * there are KMP, BM and Sunday algorithm, here Sunday algorithm is used
 * @param haystack
 * @param needle
 * @return
 */
int Solution::strStr(string haystack, string needle) {
    int pSize = needle.size();

    int i = 0, j = 0;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++; j++;
        } else {
            int newPos = i - j + pSize;
            char nCh = haystack[newPos];
            size_t nPos= needle.rfind(nCh);
            if (nPos != string::npos) {
                i = newPos - nPos;
                j = 0;
            } else {
                i = newPos;
                j = 0;
            }
        }
    }

    return j == pSize ? i - j : -1;
}

void dp(map<int, bool> &memo, int start, string s, vector<string>& words, vector<int>& ret) {
    if (memo.find(start) != memo.end()) {
        return;
    }

    int wordlen = words[0].size();
    int sublen = wordlen * words.size();

    if (start > s.size() - sublen)
        return;

    map<int, int> index_to_string;
    for (int i = 0; i < words.size(); ++i) {
        int index = s.find(words[i], start);
        if (index == s.npos) {
            return;
        }

        while (index_to_string.find(index) != index_to_string.end()) {
            index = s.find(words[i], index + wordlen);
            if (index == s.npos) {
                return;
            }
        }
        index_to_string[index] = i;
    }

    while (index_to_string.size() == words.size()) {
        int first = index_to_string.begin()->first;
        int last = index_to_string.rbegin()->first;
        int next = last + wordlen;
        if (next - first == sublen) {
            memo[first] = true;
            ret.push_back(first);
            int size = memo.size();

            int firstword = index_to_string[first];
            if (s.find(words[firstword], next) == next) {
                index_to_string[next] = firstword;
                index_to_string.erase(first);
            } else {
                dp(memo, next, s, words, ret);
                break;
            }
            dp(memo, first + 1, s, words, ret);
        } else {
            memo[first] = false;
            int firstword = index_to_string[first];
            int pos = s.find(words[firstword], first + wordlen);
            while (index_to_string.find(pos) != index_to_string.end()) {
                pos = s.find(words[firstword], pos + wordlen);
            }

            if (pos != s.npos) {
                index_to_string[pos] = firstword;
                index_to_string.erase(first);
            } else {
                return;
            }
        }
    }
    return;
}

vector<int> Solution::findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    map<int, bool> memo;
    dp(memo, 0, s, words, ret);
    sort( ret.begin(), ret.end() );
    ret.erase( unique( ret.begin(), ret.end() ), ret.end() );
    return ret;
}
