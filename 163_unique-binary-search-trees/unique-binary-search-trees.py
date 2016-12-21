# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: Python
@Datetime: 14-12-26 15:28
'''

class Solution:
    # @paramn n: An integer
    # @return: An integer
    def numTrees(self, n):
        f = [1 if i == 0 else 0 for i in xrange(0, n + 1)]
        for i in xrange(1, n + 1):
            for k in xrange(1, i + 1):
                f[i] += f[k - 1] * f[i - k]
        return f[n]