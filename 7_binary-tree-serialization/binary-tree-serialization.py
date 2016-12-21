# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-serialization
@Language: Python
@Datetime: 14-12-25 10:12
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
class Solution:

    '''
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm 
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    '''
    def serialize(self, root):
        # write your code here
        data, q = [], []
        if root == None: return data
        q.append(root)
        while len(q) > 0:
            node = q.pop(0)
            if node == None: 
                data.append('#')
            else:
                data.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
        
        while data[-1] == '#':
            data.pop()
        return data
            
        
    '''
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in 
    "serialize" method.
    '''
    def deserialize(self, data):
        # write your code here
        if len(data) == 0: return None
        root = TreeNode(data.pop(0))
        q , i = [], 0
        q.append(root)
        while i < len(data):
            node = q.pop(0)
            val, i = data[i], i + 1
            if val != '#': 
                node.left = TreeNode(int(val))
                q.append(node.left)
            if i < len(data):
                val, i = data[i], i + 1
                if val != '#':
                    node.right = TreeNode(int(val))
                    q.append(node.right)
        return root
            
