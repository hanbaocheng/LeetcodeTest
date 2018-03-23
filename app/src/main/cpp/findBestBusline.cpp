//
// Created by bhan on 3/15/18.
//
#include "Solution.h"

static vector<vector<int>> bestBuslines;

void drive(map<int, set<int>> buslinesNet, vector<int>& bestbusline, int start, int end){
    if (start == end) {
        bestBuslines.push_back(bestbusline);
        return;
    }

    set<int> stations;
    for (const int& station: bestbusline) {
        stations.insert(station);
    }

    set<int>& nextSt = buslinesNet[start];
    for (const int& next: nextSt) {
        if (stations.find(next) != stations.end())
            continue;

        bestbusline.push_back(next);
        drive(buslinesNet, bestbusline, next, end);
        bestbusline.pop_back();
    }
}

vector<int> Solution::findBestBusline(vector<vector<int>>& buslines, int start, int end) {
    vector<int> bestbusline;
    //station, (next station, line)
    map<int, set<int> /*map<int, vector<int>>*/> buslinesNet;

    for (const auto& busline: buslines) {
        for (int i = 0; i < busline.size() - 1; ++i) {
            int start = busline[i];
            int next = busline[i + 1];
            if (buslinesNet.find(start) != buslinesNet.end()) {
                set<int>& nextSt = buslinesNet[start];
                nextSt.insert(next);
            }
            else {
                set<int> nextSt;
                nextSt.insert(next);
                buslinesNet[start] = nextSt;
            }
        }

        for (int i = 1; i < busline.size(); ++i) {
            int start = busline[i];
            int last = busline[i - 1];
            if (buslinesNet.find(start) != buslinesNet.end()) {
                set<int>& nextSt = buslinesNet[start];
                nextSt.insert(last);
            }
            else {
                set<int> nextSt;
                nextSt.insert(last);
                buslinesNet[start] = nextSt;
            }
        }
    }

    if(buslinesNet.find(start) == buslinesNet.end() ||
       buslinesNet.find(end) == buslinesNet.end()) {
        return bestbusline;
    }

    bestbusline.push_back(start);
    drive(buslinesNet, bestbusline, start, end);

    return bestbusline;
}

bool matchPattern(string s, int start, int end, int& times, int& last, int& next ){
    int parentheses = 1;

    start++;
    while(start < end && parentheses != 0) {
        if (s.at(start) == '(')
            parentheses++;
        else if (s.at(start) == ')')
            parentheses--;
        start++;
    }

    if (start == end || parentheses > 0 || s.at(start) != '{')
        return false;

    last = start - 1;

    start++;
    times = 0;
    while(start < end && s.at(start) != '}') {
        int t = s.at(start) - '0';
        if (t < 0 || t > 9)
            return false;
        times = times * 10 + t;
        start++;
    }

    if(s.at(start) == '}') {
        next = start + 1;
        return true;
    }

    return false;
}

string decompress(string s, int start, int end){
    string ret = "";

    if (start == end){
        return ret;
    }

    int times = 0;
    int lastindex = end;
    int next = start;
    if(s.at(start) == '(' && matchPattern(s, start, end, times, lastindex, next)) {
        string res = decompress(s, start + 1, lastindex);
        for (int i = 0; i < times; ++i) {
            ret.append(res);
        }
        string left = decompress(s, next, end);
        ret.append(left);
        return ret;
    } else {
        ret.push_back(s.at(start));
        string left = decompress(s, start + 1, end);
        ret.append(left);
        return ret;
    }
}

string Solution::decompressStr(string s) {
    string ret = decompress(s, 0, s.size());
    return ret;
}