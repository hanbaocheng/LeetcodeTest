//
// Created by Baocheng Han on 12/5/17.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "Solution.h"
#include <iostream>
#include <stdexcept>

/**
 * lambda callable expression
 */
static const auto _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *l3 = nullptr, *last = l3;
    int carry = 0;
    if (p1 != nullptr || p1 != nullptr) {
        int var1 = 0;
        int var2 = 0;
        if (p1 != nullptr) {
            var1 = p1->val;
            p1 = p1->next;
        }

        if (p2 != nullptr) {
            var2 = p2->val;
            p2 = p2->next;
        }

        carry = (var1 + var2) / 10;
        ListNode *p3 = new ListNode((var1 + var2) % 10);
        l3 = last = p3;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int var1 = 0;
            int var2 = 0;
            if (p1 != nullptr) {
                var1 = p1->val;
                p1 = p1->next;
            }

            if (p2 != nullptr) {
                var2 = p2->val;
                p2 = p2->next;
            }

            ListNode *p3 = new ListNode((var1 + var2 + carry) % 10);
            carry = (var1 + var2 + carry) / 10;

            last->next = p3;
            last = p3;
        }
        return l3;
    } else {
        throw new std::runtime_error("Lists are null");
    }
}


