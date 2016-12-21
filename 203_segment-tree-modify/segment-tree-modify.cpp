/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/segment-tree-modify
@Language: C++
@Datetime: 15-05-14 07:33
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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == nullptr) return;
        if (root -> start == root -> end && root -> end == index) {
            root -> max = value;
            return;
        }
        int m = root -> start + (root -> end - root -> start) / 2;
        if (index <= m) modify(root -> left, index, value);
        else modify(root -> right, index, value);
        root -> max = max(root -> left -> max, root -> right -> max);
    }
};
