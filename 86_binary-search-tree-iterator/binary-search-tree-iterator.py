# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-search-tree-iterator
@Language: Python
@Datetime: 14-12-25 08:52
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None

Example of iterate a tree:
iterator = Solution(root)
while iterator.hasNext():
    node = iterator.next()
    do something for node 
"""
class Solution:
    cur, it = None, None
    #@param root: The root of binary tree.
    def __init__(self, root):
        self.it = self.inOrder(root)

    #@return: True if there has next node, or false
    def hasNext(self):
        try:
            self.cur = self.it.next()
            return True
        except:
            return False
        
    #@return: return next node
    def next(self):
        return self.cur
    
    def inOrder(self, root):
        if root == None: return;
        for x in self.inOrder(root.left): yield x
        yield root
        for x in self.inOrder(root.right): yield x
    
