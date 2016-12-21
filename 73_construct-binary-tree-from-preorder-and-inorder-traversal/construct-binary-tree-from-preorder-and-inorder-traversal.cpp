/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 14-10-21 04:32
*/

#include <vector>
#include <stdexcept>
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int> &preorder, int i, int j, vector<int> &inorder, int k,int m)
    {
        if(i>j||k>m) return NULL;
        TreeNode *root = new TreeNode(preorder[i]);
        int index =k;
        while(index<=m && inorder[index]!=root->val)
            index++;
        if(k>m) throw invalid_argument("invalid input");
        root->left = build(preorder,i+1,i+index-k,inorder,k,index-1);
        root->right = build(preorder,i+index-k+1,j,inorder,index+1,m);
        return root;
    }
};
