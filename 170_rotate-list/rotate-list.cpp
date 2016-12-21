/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 15-01-08 16:25
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;
        int n = 1;
        ListNode* p = head;
        for (; p->next; n++, p = p->next) ;
        p->next = head;
        k = n - k % n;
        for (int i = 0; i < k; p = p->next, ++i ) ;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
