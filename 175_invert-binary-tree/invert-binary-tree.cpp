/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 15-06-18 12:25
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == nullptr) return ;
        swap(root->left, root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};
