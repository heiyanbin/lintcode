/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/max-tree
@Language: C++
@Datetime: 15-11-04 03:44
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        stack<TreeNode*> s;
        A.push_back(INT_MAX);
        for (int &x : A) {
            TreeNode *p = nullptr, *q = new TreeNode(x);
            while (!s.empty() && s.top()->val <= x) {
                s.top()->right = p;
                p = s.top(); s.pop();
            }
            q->left = p;
            s.push(q);
        }
        return s.top()->left;
    }
};
