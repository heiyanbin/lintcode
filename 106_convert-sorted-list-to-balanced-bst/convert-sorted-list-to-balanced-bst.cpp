/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: C++
@Datetime: 15-01-10 06:07
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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int n = 0;
        for (auto p = head; p; p = p->next) ++n;
        return sortedListToBST(head, n);
    }
    
    TreeNode* sortedListToBST(ListNode* &head, int n) {
        if (n == 0) return NULL;
        //except the root node, diviade the left n-1 nodes into 2 halves
        auto left = sortedListToBST(head, (n - 1) / 2);
        auto root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBST(head, n - 1 - (n - 1) / 2);
        return root;
    }
};



