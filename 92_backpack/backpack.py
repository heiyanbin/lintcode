# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/backpack
@Language: Python
@Datetime: 14-12-15 16:57
'''

class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def backPack(self, m, A):
        # write your code here
        d=[0 for i in xrange(m+1)]
        for i in xrange(1,len(A)+1):
            for j in reversed(xrange(A[i-1],m+1)):
                d[j] = max(d[j], d[j-A[i-1]]+A[i-1])
        return d[m]