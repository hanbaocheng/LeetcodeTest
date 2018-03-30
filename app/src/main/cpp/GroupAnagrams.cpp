//
// Created by bhan on 3/24/18.
//
#include "Solution.h"

vector<vector<string>> Solution::groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> dic;
    for (int i = 0; i < strs.size(); ++i) {
        string s = strs[i];
        sort(s.begin(), s.end());

        vector<string> & list = dic[s];
        list.push_back(strs[i]);
    }

    vector<vector<string>> all;
    for (pair<string, vector<string>>& item: dic) {
        all.push_back(item.second);
    }

    return all;
}
