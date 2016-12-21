# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/candy
@Language: Python
@Datetime: 15-05-24 16:06
'''

class Solution:
    # @param {int[]} ratings Children's ratings
    # @return {int} the minimum candies you must give
    def candy(self, ratings):
        # Write your code here
        n, c = len(ratings), [1] * len(ratings)
        for i in xrange(1, n):
            if ratings[i] > ratings[i - 1]:
                c[i] = c[i - 1] + 1
                
        for i in xrange(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                c[i] = max(c[i + 1] + 1, c[i])
                
        return sum(c)