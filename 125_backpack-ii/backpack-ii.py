# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: Python
@Datetime: 14-12-15 17:03
'''

class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A & V: Given n items with size A[i] and value V[i]
    # @return: The maximum value
    def backPackII(self, m, A, V):
        # write your code here
        d=[0 for i in xrange(m+1)]
        for i in xrange(1,len(A)+1):
            for j in reversed(xrange(A[i-1],m+1)):
                d[j]=max(d[j],V[i-1]+d[j-A[i-1]])
        return d[m]
