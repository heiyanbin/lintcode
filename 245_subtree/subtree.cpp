/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 15-05-24 04:37
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == nullptr) return true;
        if (T1 == nullptr ) return false;
        if (isSame(T1, T2)) return true;
        return isSubtree(T1 -> left, T2) || isSubtree(T1 -> right, T2);
    }
private:
    bool isSame(TreeNode *a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (!a || !b) return false;
        return (a -> val == b -> val && isSame(a -> left, b -> left)
                && isSame(a -> right, b -> right));
    }
};
