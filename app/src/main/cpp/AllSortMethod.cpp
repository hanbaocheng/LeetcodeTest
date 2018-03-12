//
// Created by bhan on 3/12/18.
//
#include "Solution.h"
void Solution::bubble_sort(vector<int> &list) {
    for (int i = 0; i < list.size() - 1 ; ++i) {
        for (int j = 0; j < list.size() - 1 - i; ++j) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void Solution::insertion_sort(vector<int> &list) {
    for (int i = 1; i < list.size(); ++i) {
        for (int j = i; j > 0 ; --j) {
            if(list[j] < list [j - 1]) {
                int temp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = temp;
            } else
                break;
        }
    }
}


void Solution::selection_sort(vector<int> &list) {
    for (int i = 1; i < list.size(); ++i) {
        int min_index = i;
        for (int j = i; j < list.size(); ++j) {
            if(list[min_index] > list[j]) {
                min_index = j;
            }
        }
        int temp = list[min_index];
        list[min_index] = list[i - 1];
        list[i - 1] = temp;
    }
}


void merge_sort_recursive(vector<int> &list, int start, int end){
    if (start >= end) return;

    if (start + 1 == end) {
        if (list[start] > list[end]) {
            int temp = list[start];
            list[start] = list[end];
            list[end] = temp;
        }
        return;
    }

    int mid = ( end - start ) / 2 + start;
    merge_sort_recursive(list, start, mid);
    merge_sort_recursive(list, mid + 1, end);

    vector<int> templist;

    int head1 = start, head2 = mid + 1;
    while (head1 <= mid && head2 <= end)
        templist.push_back(list[head1] <= list[head2] ? list[head1++] : list[head2++] );

    while (head1 <= mid)
        templist.push_back(list[head1++]);

    while (head2 <= end)
        templist.push_back(list[head2++]);

    for (int i = 0; i < templist.size(); ++i) {
        list[start + i] = templist[i];
    }
}

void Solution::merge_sort(vector<int> &list) {
    merge_sort_recursive(list, 0, list.size() - 1);
}

void quick_sort_recursive(vector<int>& list, int start, int end){
    if (start >= end)
        return;
    int pivot = list[start];
    int i = start, j = end;
    while (i < j) {
        while (i < j && list[j] >= pivot)
            j--;
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;

        while (i < j && list[i] <= pivot)
            i++;
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;

    }

    quick_sort_recursive(list, start, i - 1);
    quick_sort_recursive(list, i + 1, end);

}

void Solution::quick_sort(vector<int> &list) {
    quick_sort_recursive(list, 0, list.size() - 1);
}