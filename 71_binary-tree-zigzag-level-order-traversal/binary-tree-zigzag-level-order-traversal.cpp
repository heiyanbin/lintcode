/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 14-10-21 03:55
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int levelNum =1, nextLevelNum=0,count=0;
        vector<int> level;
        while(!q.empty())
        {
            root=q.front();q.pop();
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
                if(count&1)
                    reverse(level.begin(),level.end());
                res.push_back(level);
                level.clear();
                levelNum=nextLevelNum;
                nextLevelNum=0;
                count++;
            }
        }
        return res;
    }
};
