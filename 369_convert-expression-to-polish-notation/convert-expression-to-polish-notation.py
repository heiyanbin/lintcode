# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/convert-expression-to-polish-notation
@Language: Python
@Datetime: 15-05-08 00:44
'''

class Solution:
    # @param expression: A string list
    # @return: The Polish notation of this expression
    def convertToPN(self, expression):
        # write your code here
        def cmp(a, b):
            if a == '#': return -1
            if b == ')': return 1
            prority = {'+' : 0, '-' : 0, '*' : 1, '/' : 1}
            return prority[a] - prority[b]
            
        stack, PN = [], []
        for token in reversed(['#'] + expression):
            if token.isdigit(): PN.append(token)
            elif token == ')': stack.append(token)
            elif token == '(':
                while len(stack) > 0 and stack[-1] != ')':
                    PN.append(stack.pop())
                if len(stack) > 0: stack.pop()
            else:
                while len(stack) > 0 and cmp(token, stack[-1]) < 0:
                    PN.append(stack.pop())
                stack.append(token)
        
        return PN[::-1]
        