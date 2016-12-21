# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interval-sum-ii
@Language: Python
@Datetime: 15-05-14 11:18
'''

class Solution:	
    class Node:
        def __init__(self, l, r):
            self.l, self.r, self.sum, self.left, self.right = l, r, 0, None, None
    # @param A: An integer list
    def __init__(self, A):
        def build(l, r):
            if l > r: return None
            root = self.Node(l, r)
            if l == r:
                root.sum = A[l]
                return root
            root.left = build(l, (l + r) / 2)
            root.right = build((l + r) / 2 + 1, r)
            root.sum = root.left.sum + root.right.sum
            return root
            
        self.root = build(0, len(A) - 1)

    # @param start, end: Indices
    # @return: The sum from start to end
    def query(self, l, r):
        def query(root, l, r):
            if root == None: return 0
            if l > r: return 0
            if l == root.l and r == root.r: return root.sum
            m = (root.l + root.r) / 2
            if r <= m: return query(root.left, l, r)
            if l >= m + 1: return query(root.right, l, r)
            return query(root.left, l, m) + query(root.right, m + 1, r)
            
        l, r = max(l, self.root.l), min(r, self.root.r)
        return query(self.root, l, r)

    # @param index, value: modify A[index] to value.
    def modify(self, index, value):
        def modify(root, index, value):
            if root == None: return
            if root.l == root.r:
                root.sum = value
                return
            m = (root.l + root.r) / 2
            if index <= m: modify(root.left, index, value)
            else: modify(root.right, index, value)
            root.sum = root.left.sum + root.right.sum
        
        if index < self.root.l or index > self.root.r: return
        modify(self.root, index, value)