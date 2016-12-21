# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/expression-tree-build
@Language: Python
@Datetime: 15-11-07 03:12
'''

"""
Definition of ExpressionTreeNode:
class ExpressionTreeNode:
    def __init__(self, symbol):
        self.symbol = symbol
        self.left, self.right = None, None
"""


class Solution:
    # @param expression: A string list
    # @return: The root of expression tree
    def build(self, expression):
        op, oprand = [], [None]
        for token in expression + ['#']:
            if token.isdigit(): oprand.append(ExpressionTreeNode(token))
            else:
                while len(op) > 0 and op[-1] != '(' and token != '(' and (token in '+-)#' or op[-1] in '*/'):
                    node = ExpressionTreeNode(op.pop())
                    node.right = oprand.pop();
                    node.left = oprand.pop();
                    oprand.append(node);
                if token == ')': op.pop()
                else: op.append(token)
        return oprand[-1]
