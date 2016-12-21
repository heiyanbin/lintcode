/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-node-in-binary-search-tree
@Language: C++
@Datetime: 14-11-12 04:36
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
#include <cassert>
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(root==NULL) return NULL;
        if(value<root->val) root->left = removeNode(root->left,value);
        else if(value>root->val) root->right = removeNode(root->right,value);
        else
        {
            if(root->left==NULL)
            {
                auto right = root->right;
                delete root;
                return right;
            }
            if(root->right==NULL)
            {
                auto left = root->left;
                delete root;
                return left;
            }
            auto x = min(root->right);
            x->right = delMin(root->right);
            x->left = root->left;
            delete root;
            return x;
        }
        return root;
    }
    
    TreeNode *delMin(TreeNode* root)
    {
        if(root==NULL) return NULL;
        if(root->left==NULL)
            return root->right;
        else
            root->left = delMin(root->left);
        return root;
    }
    TreeNode *min(TreeNode* root)
    {
        assert(root);
        while(root->left)
            root=root->left;
        return root;
    }
};
