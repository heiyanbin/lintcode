# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interval-sum
@Language: Python
@Datetime: 15-05-14 09:00
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
    def intervalSum(self, A, queries):
        class Node:
            def __init__(self, l, r):
                self.l, self.r, self.sum, self.left, self.right = l, r, 0, None, None
                
        def build(A, l, r):
            if l > r: return None
            root = Node(l, r)
            if l == r:
                root.sum = A[l]
                return root
            root.left = build(A, l, (l + r) / 2)
            root.right = build(A, (l + r) / 2 + 1, r)
            root.sum = root.left.sum + root.right.sum
            return root
            
        def query(root, l, r):
            if root.l == l and root.r == r: return root.sum
            m = (root.l + root.r) / 2
            if r <= m: return query(root.left, l, r)
            elif l >= m + 1: return query(root.right, l, r)
            return query(root.left, l, m) + query(root.right, m + 1, r)
            
        root, res = build(A, 0, len(A) - 1), []
        for q in queries: res.append(query(root, q.start, q.end))
        return res
