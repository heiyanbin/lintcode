/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 14-11-20 14:27
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode dummy_left(-1), dummy_right(-1), *end_left=&dummy_left, *end_right=&dummy_right;
        for(;head;head=head->next)
        {
            if(head->val<x) 
            {
                end_left->next= head;
                end_left=head;
            }
            else
            {
                end_right->next= head;
                end_right=head;
            }
        }
        end_left->next=dummy_right.next;
        end_right->next=NULL;
        return dummy_left.next;
    }
};



