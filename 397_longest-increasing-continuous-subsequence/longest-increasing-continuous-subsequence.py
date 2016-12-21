# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: Python
@Datetime: 15-05-25 01:37
'''

class Solution:
    # @param {int[]} A an array of Integer
    # @return {int}  an integer
    def longestIncreasingContinuousSubsequence(self, A):
        # Write your code here
        if len(A) == 0: return 0
        maxLen, curLen = 1, 1
        for i in xrange(1, len(A)):
            if A[i] >= A[i - 1]:
                curLen += 1
                maxLen = max(maxLen, curLen)
            else:
                curLen = 1
        
        curLen = 1
        for i in xrange(1, len(A)):
            if A[i] <= A[i - 1]:
                curLen += 1
                maxLen = max(maxLen, curLen)
            else:
                curLen = 1
                
        return maxLen
