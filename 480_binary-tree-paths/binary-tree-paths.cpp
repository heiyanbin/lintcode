/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 15-12-10 02:47
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> ans;
        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path)->void {
            if (node == nullptr) return;
            path = path.empty() ? to_string(node->val) : path + "->" + to_string(node->val);
            if (!node->left && !node->right) ans.push_back(path);
            dfs(node->left, path);
            dfs(node->right, path);
        };
        dfs(root, "");
        return ans;
    }
};