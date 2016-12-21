/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 14-12-29 04:10
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode dummy(-1), *prevM = &dummy;
        dummy.next = head;
        for (int i = 0; i < m - 1 && prevM; ++i, prevM = prevM->next) ;
        if (!prevM || !prevM->next || !prevM->next->next) return head;
        auto &head2 = prevM->next, cur = prevM->next, start = prevM->next;
        for (int i = m; i <= n && cur; ++i) {
            auto next = cur->next;
            cur->next = head2;
            head2 = cur;
            cur = next;
        }
        start->next = cur;
        return dummy.next;
    }
};

