/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 14-11-22 06:57
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        for(auto p=head;p;)
        {
            auto next = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = next;
            p=next;
        }
        for(auto p=head;p;p=p->next->next)
        {
            auto q= p->next;
            if(p->random)
                q->random=p->random->next;
        }
        RandomListNode dummy(-1), *prev=&dummy;
        for(auto p=head;p;prev=prev->next)
        {
            prev->next=p->next;
            p->next=p->next->next;
            p=p->next;
        }
        return dummy.next;
    }
};
