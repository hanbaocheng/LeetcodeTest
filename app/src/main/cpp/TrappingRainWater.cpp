//
// Created by bhan on 3/20/18.
//
#include "Solution.h"

int Solution::trap(vector<int> &height) {
    map<int, vector<int>> twoedge;
    int max = 0;
    vector<int> edges;
    edges.push_back(max);
    twoedge[0] = edges;

    for (int i = 1; i < height.size(); ++i) {
        if (height[i - 1] > max) {
            max = height[i - 1];
        }

        vector<int> edges;
        edges.push_back(max);
        twoedge[i] = edges;
    }

    max = 0;
    vector<int>& edge = twoedge[height.size() - 1];
    edge.push_back(max);

    for (int i = height.size() - 2; i >= 0; --i) {
        if (height[i + 1] > max) {
            max = height[i + 1];
        }

        vector<int>& edge = twoedge[i];
        edge.push_back(max);
    }

    int sum = 0 ;
    for (int i = 0; i < height.size(); ++i) {
        int left = twoedge[i][0];
        int right = twoedge[i][1];

        if(height[i] < left && height[i] < right) {
            sum += (left < right ? left : right) - height[i];
        }
    }

    return sum;
}
