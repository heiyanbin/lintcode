/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-search-tree-iterator
@Language: C++
@Datetime: 14-11-14 04:00
*/

/**
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        inOrder(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !q.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        auto item = q.front();
        q.pop();
        return item;
    }
private:
    queue<TreeNode*> q;
    void inOrder(TreeNode* root)
    {
        if(root==NULL) return;
        inOrder(root->left);
        q.push(root);
        inOrder(root->right);
    }
};
