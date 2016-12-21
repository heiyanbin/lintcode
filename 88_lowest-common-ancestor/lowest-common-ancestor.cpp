/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/lowest-common-ancestor
@Language: C++
@Datetime: 14-11-14 03:41
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root==NULL||A==NULL||B==NULL||A==B||A==root||B==root) return root;
        auto left = lowestCommonAncestor(root->left, A, B);
        auto right = lowestCommonAncestor(root->right, A, B);
        if(left && right ) return root;
        return left ? left : right;
    }
    
};
