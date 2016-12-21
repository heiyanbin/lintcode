/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 14-11-17 04:37
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head==NULL||head->next==NULL||head->next->next==NULL) return;
        auto p=head, q=head;
        while(q&& q->next)
        {
            q=q->next->next;
            p=p->next;
        }
        auto tmp= p->next;
        p->next=NULL;
        
        ListNode *head2=NULL;
        while(tmp)
        {
            auto next = tmp->next;
            tmp->next = head2;
            head2 = tmp;
            tmp=next;
        }
        while(head && head2)
        {
            auto next = head->next, next2 = head2->next;
            head->next= head2;
            head2->next= next;
            head=next;
            head2=next2;
        }
    }
};



