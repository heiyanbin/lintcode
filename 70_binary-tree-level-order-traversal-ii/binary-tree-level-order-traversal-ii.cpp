/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
@Language: C++
@Datetime: 14-10-21 03:20
*/

#include <vector>
#include <algorithm>
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderButtom(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        int levelNum =1, nextLevelNum=0;
        while(!q.empty())
        {
            root= q.front();q.pop();
            level.push_back(root->val);
            levelNum--;
            if(root->left) 
            {
                q.push(root->left);
                nextLevelNum++;
            }
            if(root->right) 
            {
                q.push(root->right);
                nextLevelNum++;
            }
            if(levelNum==0)
            {
                res.push_back(level);
                level.clear();
                levelNum= nextLevelNum;
                nextLevelNum=0;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
