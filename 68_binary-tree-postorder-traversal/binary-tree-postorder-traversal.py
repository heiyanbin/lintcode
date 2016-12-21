# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: Python
@Datetime: 14-12-25 14:38
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
    @return: Postorder in ArrayList which contains node values.
    """
    def postorderTraversal(self, root):
        # write your code here
        res, stack, prev = [], [], None
        while root != None or len(stack) > 0:
            if root != None:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                if root.right != None and prev != root.right: #in postOrder, root's prev is root.right
                    stack.append(root)
                    root = root.right
                else:
                    res.append(root.val)
                    prev , root = root, None
        return res