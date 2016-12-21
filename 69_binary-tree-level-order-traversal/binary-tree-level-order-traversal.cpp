/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 14-10-21 03:09
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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        auto levelEnd = root;
        vector<int> level;
        while(!q.empty())
        {
            root = q.front();q.pop();
            level.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            if(root==levelEnd)
            {
                res.push_back(level);
                level.clear();
                if(!q.empty())
                    levelEnd=q.back();
            }
        }
        return res;
    }
};

