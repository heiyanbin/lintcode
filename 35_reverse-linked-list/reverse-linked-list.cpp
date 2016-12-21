/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 14-12-28 13:35
*/

#include "lintcode.h"

using namespace std;

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *head2 = NULL;
        while (head) {
            auto next = head->next;
            head->next = head2;
            head2 = head;
            head = next;
        }
        return head2;
    }
};

