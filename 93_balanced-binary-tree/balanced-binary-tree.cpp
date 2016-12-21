/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 14-11-11 04:19
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
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return balancedHeight(root)>=0;
    }
private:
    int balancedHeight(TreeNode *root)
    {
        if(root==NULL) return 0;
        int left = balancedHeight(root->left);
        if(left<0) return -1;
        int right = balancedHeight(root->right);
        if(right<0) return -1;
        return abs(left-right)<=1 ? max(left,right)+1 : -1;
    }
};
