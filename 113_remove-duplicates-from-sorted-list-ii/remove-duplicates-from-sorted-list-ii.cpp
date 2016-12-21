/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: C++
@Datetime: 14-12-29 11:29
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode dummy(-1), *prev= &dummy;
        dummy.next = head;
        while (head) {
            bool delHead = false;
            while (head->next && head->next->val == head->val) {
                auto tmp = head->next->next;
                delete head->next;
                head->next = tmp;
                delHead = true;
            }
            if (!delHead) {
                prev = head;
                head = head->next;
            }
            else {
                auto tmp = head->next;
                delete head;
                head = tmp;
                prev->next = head;
            }
        }
        return dummy.next;
    }
};
