/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 14-10-21 02:57
*/

#include <vector>
#include "lintcode.h"

using namespace std;

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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> s;
        vector<int> res;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();s.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};
