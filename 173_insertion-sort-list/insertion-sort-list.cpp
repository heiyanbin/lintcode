/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 15-05-20 06:41
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode * head2 = nullptr;
        for (auto p = head; p;) {
            auto next = p -> next;
            head2 = insert(head2, p);
            p = next;
        }
        return head2;
    }
    
    ListNode *insert(ListNode *head, ListNode *x) {
        if (head == nullptr || x -> val <= head -> val) {
            x -> next = head;
            return x;
        }
        head -> next = insert(head -> next, x);
        return head;
    }
};
