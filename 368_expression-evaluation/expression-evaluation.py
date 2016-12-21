# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/expression-evaluation
@Language: Python
@Datetime: 15-06-23 14:59
'''

class Solution:
    # @param expression: a list of strings;
    # @return: an integer
    def evaluateExpression(self, expression):
        m = {'+' : lambda a, b : a + b, '-' : lambda a, b : a - b, '*' : lambda a, b : a * b, '/' : lambda a, b : a / b}
        op, oprand = [], []
        for token in expression + ['#']:
            if token.isdigit(): oprand.append(int(token))
            else:
                while len(op) > 0 and token != '(' and op[-1] != '(' and  (token in '#)+-' or op[-1] in '*/'):
                    b = oprand.pop();
                    oprand[-1] = m[op.pop()](oprand[-1], b)
                if token == ')': op.pop()
                else: op.append(token)
        if len(oprand) > 0: return oprand[-1]
        return 0
        
    
        
        
    