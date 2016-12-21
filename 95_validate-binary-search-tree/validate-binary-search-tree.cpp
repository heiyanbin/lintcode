/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 15-01-04 06:05
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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        return isBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
    bool isBST(TreeNode * root, long long lower_bound, long long upper_bound)
    {
        if (root == NULL) return true;
        return(root->val < upper_bound && root->val > lower_bound 
                && isBST(root->left, lower_bound, root->val)
                && isBST(root->right, root->val, upper_bound));
    }
};
