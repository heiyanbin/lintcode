# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: Python
@Datetime: 14-12-25 14:08
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
    @param root: The root of binary tree.
    @return: Preorder in ArrayList which contains node values.
    """
    def preorderTraversal(self, root):
        # write your code here
        if root == None: return []
        stack, res = [], []
        stack.append(root)
        while len(stack) > 0:
            node = stack.pop()
            res.append(node.val)
            if node.right != None:
                stack.append(node.right)
            if node.left != None:
                stack.append(node.left)
        return res
            