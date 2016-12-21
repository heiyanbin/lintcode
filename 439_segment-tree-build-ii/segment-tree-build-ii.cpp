/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/segment-tree-build-ii
@Language: C++
@Datetime: 15-09-01 01:37
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.empty()) return nullptr;
        return build(A, 0, A.size() - 1);
    }
private:
    SegmentTreeNode * build(vector<int>& A, int l, int r) {
        if (l == r) return  new SegmentTreeNode(l, r, A[l]);
        auto root = new SegmentTreeNode(l, r, 0);
        int m = l + (r - l) / 2;
        root->left = build(A, l, m);
        root->right = build(A, m + 1, r);
        root->max = max(root->left->max, root->right->max);
        return root;
    }
};
