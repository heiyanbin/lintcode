/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/rehashing
@Language: C++
@Datetime: 14-12-08 13:59
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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = hashTable.size()*2;
        vector<ListNode*> table(capacity);
        for(auto slot: hashTable)
            if(slot)
            {
                for(auto p=slot;p;)
                {
                    ListNode *next = p->next;
                    int index=p->val>= 0 ? p->val%capacity :capacity + p->val %capacity;
                    if(table[index]==NULL) table[index]=p;
                    else{
                        ListNode *cur;
                        for(cur=table[index];cur->next;cur=cur->next);
                        cur->next = p;
                    }
                    p->next=NULL;
                    p=next;
                }
            }
        return table;
    }
};

