# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: Python
@Datetime: 15-05-25 01:23
'''

class Solution:
    # @param A: a list of non-negative integers.
    # return: an integer
    def houseRobber(self, A):
        # write your code here
        if len(A) == 0: return 0
        a, b = 0, A[0]
        for i in xrange(1, len(A)):
            c = max(A[i] + a, b)
            a, b = b, c
        return b
        