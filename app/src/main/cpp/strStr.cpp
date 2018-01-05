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

vector<int> Solution::findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    map<string, int> dict;


    auto resetDict = [&dict, words](){
        for (int i = 0; i < words.size(); ++i) {
            string str = words[i];
            dict[str] = 0;
        }

        for (int i = 0; i < words.size(); ++i) {
            dict[words[i]] =  ++dict[words[i]];
        }
    };

    auto findFirstMatch = [s, words](int start)->int{
        int min = s.find(words[0],start);
        if (min == s.npos)
            return -1;

        for (int i = 1; i < words.size(); ++i) {
            int index = s.find(words[i],start);
            if (index < min )
                min = index;

        }
        return min;
    };

    auto isMatch = [&dict]()->bool {
        for (auto const &item: dict) {
            if (item.second != 0)
                return false;
        }
        return true;
    };

    int start = 0;
    int sSize = s.size();
    int wSize = words[0].size();
    int lSize = words.size() * wSize;

    while (sSize - start >= lSize) {
        int begin = findFirstMatch(start);
        if (begin == -1)
            break;

        start = begin;
        resetDict();

        int i = 0;
        for ( i = 0; i < words.size(); ++i) {
            string word = s.substr(begin, wSize);
            if (dict.find(word) == dict.end()) {
                break;
            } else {
                dict[word] = --dict[word];
            }
            begin += wSize;
        }

        if (i == words.size() && isMatch()) {
            ret.push_back(begin - lSize);
        }
        start = start + 1;
    }

    return ret;
}
