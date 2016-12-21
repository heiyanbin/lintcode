/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 14-10-21 03:42
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root->right) 
                    s.push(root->right);
                root=root->left;
            }
            else
            {
                root=s.top();s.pop();
            }
        }
        return res;
    }
};

