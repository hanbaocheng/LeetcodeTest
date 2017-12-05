//
// Created by Baocheng Han on 12/5/17.
//

#ifndef MEDIONFILEEXPLORER_ADDTWONUMBERS_H
#define MEDIONFILEEXPLORER_ADDTWONUMBERS_H

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};


#endif //MEDIONFILEEXPLORER_ADDTWONUMBERS_H
