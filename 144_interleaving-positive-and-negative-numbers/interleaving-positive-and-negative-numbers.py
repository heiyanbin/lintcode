# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers
@Language: Python
@Datetime: 14-12-23 10:46
'''

class Solution:
    """
    @param A: An integer array.
    @return an integer array
    """
    def rerange(self, A):
        i, j, n =0, 0, len(A)
        for j in xrange (0, n):
            if A[j] < 0:
                A[i], A[j] = A[j], A[i]
                i += 1
        i, j = (0, 1) if i >= n - i else (1, 0)
        while i<n and j<n:
            while i<n and A[i]<0: i += 2
            while j<n and A[j]>0: j += 2
            if i < n and j < n: A[i], A[j] = A[j], A[i]
        return A
              
