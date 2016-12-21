# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interval-minimum-number
@Language: Python
@Datetime: 15-05-14 08:21
'''

"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:	
    """
    @param A, queries: Given an integer array and an Interval list
                       The ith query is [queries[i-1].start, queries[i-1].end]
    @return: The result list
    """
    def intervalMinNumber(self, A, queries):
        # write your code here
        class Node:
            def  __init__(self, s, e):
                self.start, self.end, self.min, self.left, self.right = s, e, 0, None, None
                
        def build(A, start, end):
            if start > end: return None
            root = Node(start, end)
            if start == end:
                root.min = A[start]
                return root
            root.left = build(A, start, (start + end) / 2)
            root.right = build(A, (start + end) / 2 + 1, end)
            root.min = min(root.left.min, root.right.min)
            return root
            
        def query(root, start, end):
            if start == root.start and end == root.end: return root.min
            m = root.start + (root.end - root.start) / 2
            if end <= m: return query(root.left, start, end)
            elif start >= m + 1: return query(root.right, start, end)
            return min(query(root.left, start, m), query(root.right, m + 1, end))
            
        root, res = build(A, 0, len(A) - 1), []
        for q in queries: res.append(query(root, q.start, q.end))
        return res
                
                