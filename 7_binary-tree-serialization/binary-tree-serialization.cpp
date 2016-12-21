/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-serialization
@Language: C++
@Datetime: 15-08-20 02:17
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string s;
        function<void(TreeNode*)> preOrder = [&](TreeNode* root) {
            if (!root) s.append("# ");
            else {
                s.append(to_string(root->val) + ' ');
                preOrder(root->left);
                preOrder(root->right);
            }
        };
        preOrder(root);
        return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        if (data.empty()) return nullptr;
        int i = 0;
        function<TreeNode*()> preOrder = [&]()->TreeNode* {
            auto j = i++;
            for (; i < data.size() && data[i] != ' '; ++i);
            ++i;
            if (data[j] == '#') return nullptr;
            auto root = new TreeNode(stoi(data.substr(j, i - j - 1)));
            root->left = preOrder();
            root->right = preOrder();
            return root;
        };
        return preOrder();
    }
};

