/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/linked-list-cycle
@Language: C++
@Datetime: 14-11-20 05:49
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        for(auto p=head, q=head;q&&q->next;)
        {
            p=p->next;
            q=q->next->next;
            if(p==q) return true;
        }
        return false;
    }
};



