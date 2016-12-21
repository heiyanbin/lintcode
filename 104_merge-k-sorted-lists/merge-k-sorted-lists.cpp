/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 15-05-29 16:34
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto &e : lists) {
            if (e) pq.push(e);
        }
        ListNode dummy(-1), *prev = &dummy;
        while (!pq.empty()) {
            prev->next = pq.top(); pq.pop();
            prev = prev->next;
            if (prev->next) pq.push(prev->next);
        }
        return dummy.next;
    }
    struct cmp {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
};



