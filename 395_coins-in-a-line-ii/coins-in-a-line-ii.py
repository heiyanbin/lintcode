# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/coins-in-a-line-ii
@Language: Python
@Datetime: 15-05-25 00:24
'''

class Solution:
    # @param values: a list of integers
    # @return: a boolean which equals to True if the first player will win
    def firstWillWin(self, values):
        n = len(values)
        if n <= 2: return True
        a, b, s = max(values[-2], sum(values[-2:])), values[-1], sum(values[-2:])
        for i in xrange(n - 3, -1, -1):
            c = max(values[i] + s - a, values[i] + values[i+1] + s - values[i + 1] - b)
            a, b, s  = c, a, s + values[i]
            
        return a > s - a