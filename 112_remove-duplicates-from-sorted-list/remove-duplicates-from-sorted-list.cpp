/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 14-12-29 11:14
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        for (auto cur = head; cur; ) {
            while (cur->next && cur->next->val == cur->val) {
                auto tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};
