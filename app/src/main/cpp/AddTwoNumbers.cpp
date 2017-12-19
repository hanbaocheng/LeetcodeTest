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


ListNode* Solution::getList(vector<int> list){
    ListNode header(0);
    ListNode* l = &header;
    for(int i: list) {
        ListNode* n = new ListNode(i);
        l->next = n;
        l = n;
    }

    return  header.next;
}
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

ListNode *Solution::removeNthFromEnd(ListNode *head, int n) {
    int size = 0;
    ListNode header(0);
    header.next = head;

    ListNode* itor = header.next;
    while (itor) {
        size++;
        itor = itor->next;
    }

    itor = &header;
    int del = size -n;
    while (del > 0 && itor) {
        itor = itor->next;
    }
    ListNode* delNode = itor->next;
    itor->next = delNode->next;
    delete delNode;

    return header.next;
}


ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode header(0);
    ListNode* l3 = &header;

    ListNode* head1 = l1;
    ListNode* head2 = l2;
    ListNode* head3 = l3;

    while (head1 || head2) {
        if (head1 == nullptr) {
            head3->next = head2;
            break;
        }
        if (head2 == nullptr) {
            head3->next = head1;
            break;
        }

        if(head1->val == head2->val) {
            head3->next = head1;
            head3 = head3->next;
            head1 = head1->next;

            head3->next = head2;
            head3 = head3->next;
            head2 = head2->next;
        } else if (head1->val > head2->val) {
            head3->next = head2;
            head3 = head3->next;
            head2 = head2->next;
        } else {
            head3->next = head1;
            head3 = head3->next;
            head1 = head1->next;
        }
    }

    return l3->next;
}

ListNode* Solution::mergeKLists(vector<ListNode *> &lists) {
    ListNode header(0);
    ListNode* list = &header;
    map<int, vector<ListNode *>> minRange;

    for (int i = 0; i < lists.size(); ++i) {
        if(lists[i] != nullptr) {
            minRange[lists[i]->val].push_back(lists[i]);
        }
    }

    while (minRange.size() > 0) {
        map<int, vector<ListNode *>>::iterator it = minRange.begin();
        if (minRange.size() == 1 && it->second.size() == 1) {
            ListNode* min = it->second[0];
            list->next = min;
            break;
        }

        for (int i = 0; i < it->second.size(); ++i) {
            ListNode* min = it->second[i];

            list->next = min;
            list = list->next;
            min = min->next;
            if (min != nullptr)
                minRange[min->val].push_back(min);
        }

        minRange.erase(it);
    }

    return header.next;
}

ListNode* Solution::swapPairs(ListNode *head) {
    ListNode header(0);
    header.next = head;
    ListNode* l = &header;

    while (l->next && l->next->next) {
        ListNode* first = l->next;
        ListNode* second = l->next->next;

        first->next = second->next;
        l->next = second;
        second->next = first;

        l = l->next->next;
    }

    return header.next;
}
