# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/triangle-count
@Language: Python
@Datetime: 15-05-19 04:16
'''

class Solution:
    # @param S: a list of integers
    # @return: a integer
    def triangleCount(self, S):
        # write your code here
        S.sort()
        count = 0;
        for i in xrange(0, len(S) - 2):
            p = i + 1
            for q in xrange(i + 2, len(S)):
                while p < q and S[i] + S[p] <= S[q]:
                    p += 1
                count += q - p
        return count
                