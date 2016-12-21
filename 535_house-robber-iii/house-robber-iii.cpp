/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/house-robber-iii
@Language: C++
@Datetime: 16-06-16 09:58
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        return help(root, true);
    }
    
private:
    int help(TreeNode* root, bool couldRobRoot) {
        if (root == nullptr) return 0;
        
        if (couldRobRoot) {
            auto it = cache.find(root);
            if (it != cache.end()) {
                return it->second;
            }
            else {
                int ret = max(
                    help(root->left, true) + help(root->right, true),
                    root->val + help(root->left, false) + help(root->right, false));
                    
                return cache[root] = ret;
            }
        }
        else {
            return help(root->left, true) + help(root->right, true);
        }
    }
    
    unordered_map<TreeNode*, int> cache;
};