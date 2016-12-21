/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 15-01-08 16:42
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1), *prev = &dummy;
        for (int carry = 0; l1 || l2 || carry; prev = prev->next) {
            int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            prev->next = new ListNode(value % 10);
            carry = value / 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy.next;
    }
};
