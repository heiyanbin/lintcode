/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/linked-list-cycle-ii
@Language: C++
@Datetime: 14-12-28 14:37
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        auto p = head, q=head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) break;
        }
        if (p != q) return NULL;
        for (p = head; p != q; p = p->next, q=q->next);
        return p;
    }
};



