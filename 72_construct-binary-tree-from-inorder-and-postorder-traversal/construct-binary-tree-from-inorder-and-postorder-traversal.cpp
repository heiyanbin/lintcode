/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 14-10-21 04:52
*/

#include <vector>
#include <cassert>
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int> &inorder, int i, int j, vector<int> &postorder, int k, int m)
    {
        if(i>j||k>m) return NULL;
        auto root = new TreeNode(postorder[m]);
        int t=i;
        while(t<=j && inorder[t]!=root->val)
            t++;
        assert(t<=j);
        root->left=build(inorder,i,t-1,postorder,k,k+t-i-1);
        root->right=build(inorder,t+1,j,postorder,k+t-i,m-1);
        return root;
    }
};
