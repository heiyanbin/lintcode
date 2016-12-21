/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/swap-two-nodes-in-linked-list
@Language: C++
@Datetime: 16-06-17 08:58
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
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if (head == nullptr) return nullptr;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode* pre1 = &dummy, *pre2 = &dummy;
        bool found1 = false, found2 = false;
        
        for (ListNode *p = head; p; p = p->next) {
            if (!found1 && p->val == v1) {
                found1 = true;   
            }
            
            if (!found2 && p->val == v2) {
                found2 = true;
            }
            
            if (found1 && found2) break;
            
            if (!found1) {
                pre1 = p;
            }
            if (!found2) {
                pre2 = p;
            }
        }
        
        if (!found1 || !found2) return dummy.next;
        
        auto cur1 = pre1->next, cur2 = pre2->next;
        auto next1 = cur1->next, next2 = cur2->next;
        
        if (cur1->next == cur2) {
			cur1->next = cur2->next;
			cur2->next = cur1;
			pre1->next = cur2;
		}
		else if (cur2->next == cur1) {
			cur2->next = cur1->next;
			cur1->next = cur2;
			pre2->next = cur1;
		}
		else {
			pre1->next = cur2;
			cur2->next = next1;

			pre2->next = cur1;
			cur1->next = next2;
		}
        
        return dummy.next;
        
    }
};