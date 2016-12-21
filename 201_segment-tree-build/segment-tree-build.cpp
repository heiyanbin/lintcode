/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/segment-tree-build
@Language: C++
@Datetime: 15-04-14 04:50
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        
        if (start > end) return nullptr;
        auto root = new SegmentTreeNode(start, end);
        if (start < end) {
            root -> left = build(start, (start + end) / 2);
            root -> right = build((start + end) / 2 + 1, end);
        }
        return root;
    }
};
