/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees-ii
@Language: C++
@Datetime: 14-12-27 02:19
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }
        for (int k = start; k <= end; ++k) {
            vector<TreeNode*> leftTrees = generateTrees(start, k - 1);
            vector<TreeNode*> rightTrees = generateTrees(k + 1, end);
            for (auto &l : leftTrees)
                for (auto &r : rightTrees) {
                    auto root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
        }
        return trees;
    }
};
