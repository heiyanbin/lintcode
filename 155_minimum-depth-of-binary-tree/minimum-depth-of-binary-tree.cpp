/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 14-12-24 09:52
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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left) return minDepth(root->left) + 1;
        return minDepth(root->right) + 1;
    }
};
