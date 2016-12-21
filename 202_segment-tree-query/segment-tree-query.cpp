/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/segment-tree-query
@Language: C++
@Datetime: 15-05-14 08:12
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root -> start == start && root -> end == end) return root -> max;
        int m = (root -> start + root -> end) / 2;
        if (end <= m) return query(root -> left, start, end);
        if (start > m) return query(root -> right, start, end);
        return max(query(root -> left, start, m), query(root -> right, m + 1, end));
        
    }
};
