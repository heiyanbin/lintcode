/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-maximum-path-sum
@Language: C++
@Datetime: 15-07-05 03:13
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
    int maxPathSum(TreeNode *root) {
        return dfs(root).second;
    }
private:
    pair<int, int> dfs(TreeNode * root) {
        if (!root) return {0, INT_MIN};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        pair<int, int> cur;
        cur.first = max(max(l.first, r.first) + root->val, root->val);
        cur.second = root->val;
        if (l.first > 0) cur.second += l.first;
        if (r.first > 0) cur.second += r.first;
        cur.second = max(cur.second, max(l.second, r.second));
        return cur;
    }
};
