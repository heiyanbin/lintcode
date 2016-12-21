# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/k-sum
@Language: Python
@Datetime: 14-12-23 01:05
'''

class Solution:
    """
    @param A: An integer array.
    @param k: a positive integer (k <= length(A))
    @param target: integer
    @return an integer
    """
    def kSum(self, A, k, target):
        # write your code here
        d = [[0]*(k+1) for i in xrange (target + 1)]
        d[0][0] = 1
        for i in xrange (1, len(A) + 1):
            for j in xrange (target, A[i-1]-1, -1):
                for  l in xrange (k, 0, -1):
                    d[j][l] = d[j][l] + d[j-A[i-1]][l-1]
        return d[target][k]