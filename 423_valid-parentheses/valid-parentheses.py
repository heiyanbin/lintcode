# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: Python
@Datetime: 15-06-01 05:11
'''

class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        # Write your code here
        left, right, stack = '([{', ')]}', []
        for c in s:
            if c in left:
                stack.append(c)
            elif len(stack) == 0 or left.index(stack[-1]) != right.index(c):
                return False
            else:
                stack.pop(-1)
        return len(stack) == 0
                
        