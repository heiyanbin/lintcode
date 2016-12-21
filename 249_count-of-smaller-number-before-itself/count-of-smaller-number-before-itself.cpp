/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number-before-itself
@Language: C++
@Datetime: 15-05-13 10:14
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        TreeNode *root = NULL;
        vector<int> res;
        for (int e : A) {
            res.push_back(rank(root, e));
            root = insert(root, e);
        }
        return res;
    }
private:
    struct TreeNode {
        int val, size;
        TreeNode *left, *right;
        TreeNode(int v) : val(v), size(1), left(NULL), right(NULL) {}
    };
    TreeNode* insert(TreeNode * root, int x) {
        if (root == NULL) return new TreeNode(x);
        if (x <= root->val) root -> left = insert(root -> left, x);
        else root -> right = insert(root -> right, x);
        root->size = size(root->left) + size(root->right) + 1;
        return root;
    }
    int rank(TreeNode * root, int x) {
        if (root == NULL) return 0;
        if (x <= root->val) return rank(root->left, x);
        return size(root->left) + 1 + rank(root->right, x);
    }
    int size(TreeNode * root) {
        if (root == NULL) return 0;
        return root->size;
    }
};
