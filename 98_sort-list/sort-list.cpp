/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: C++
@Datetime: 14-12-28 12:49
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return head;
        return sortList(head, NULL);
        
    }
    ListNode *sortList(ListNode *head, ListNode *end) {
        if (head == end ) return head;
        ListNode dummy_left(-1), dummy_right(-1);
        dummy_right.next = head;
        auto left_end = &dummy_left, right_end = head;
        for (auto p = head->next; p != end;) {
            auto next = p->next;
            if (p->val < head->val) {
                left_end->next = p;
                left_end = p;
            } else if ( p->val == head->val) {
                p->next = dummy_right.next;
                dummy_right.next = p;
            } else {
                right_end->next = p;
                right_end = p;
            }
            p = next;
        }
        left_end->next = dummy_right.next;
        right_end->next = end;
        auto newHead = sortList(dummy_left.next, dummy_right.next);
        head->next = sortList(head->next, end);
        return newHead;
    }
};



