# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/convert-expression-to-reverse-polish-notation
@Language: Python
@Datetime: 15-06-24 02:18
'''

class Solution:
    # @param expression: A string list
    # @return: The Reverse Polish notation of this expression
    def convertToRPN(self, expression):
        stack, RPN = [], []
        for token in expression + ['#']:
            if token.isdigit(): RPN.append(token)
            else:
                while len(stack) > 0 and token != '(' and stack[-1] != '(' and (token in '#)+-' or stack[-1] in '*/'):
                    RPN.append(stack.pop())
                if token == ')': stack.pop()
                else: stack.append(token)
        return RPN
                    
