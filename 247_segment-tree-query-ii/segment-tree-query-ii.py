# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/segment-tree-query-ii
@Language: Python
@Datetime: 15-05-14 10:22
'''

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end, count):
        this.start, this.end, this.count = start, end, count
        this.left, this.right = None, None
"""

class Solution:	
    # @param root, start, end: The root of segment tree and 
    #                          an segment / interval
    # @return: The count number in the interval [start, end] 
    def query(self, root, start, end):
        # write your code here
        if root == None: return 0
        if start < root.start: start = root.start
        if end > root.end: end = root.end
        if root.start == start and root.end == end: return root.count
        m = (root.start + root.end) / 2
        if end <= m: return self.query(root.left, start, end)
        elif start >= m + 1: return self.query(root.right, start, end)
        return self.query(root.left, start, m) + self.query(root.right, m + 1, end)
