# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: Python
@Datetime: 15-05-19 04:20
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
class Solution:
    """
    @param A: a list of integer
    @return: a tree node
    """
    def sortedArrayToBST(self, A):
        # write your code here
        def build(A, i, j):
            if i > j: return None
            m = i + (j - i) / 2
            root = TreeNode(A[m])
            root.left = build(A, i, m - 1)
            root.right = build(A, m + 1, j)
            return root
            
        return build(A, 0, len(A) - 1)

