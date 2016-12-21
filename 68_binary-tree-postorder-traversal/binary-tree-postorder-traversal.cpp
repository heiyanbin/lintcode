/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 14-10-21 03:38
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
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
                if(root->right && root->right!=prev)
                {
                    s.push(root);
                    root=root->right;
                }
                else
                {
                    res.push_back(root->val);
                    prev=root;
                    root=NULL;
                }
            }
        }
        return res;
    }
};
