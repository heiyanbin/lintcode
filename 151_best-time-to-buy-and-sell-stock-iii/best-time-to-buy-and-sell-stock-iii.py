# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: Python
@Datetime: 15-01-21 16:24
'''

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        n = len(prices)
        if n <= 1: return 0
        f , low = [0] * n, sys.maxint
        for i in xrange(0, n):
            low = min(low, prices[i])
            f[i] = prices[i] - low
            
        res, high, profit = 0, -1, 0
        for i in xrange(n - 1, -1, -1):
            high = max(high, prices[i])
            profit = max(profit, high - prices[i])
            res = max(res, profit + f[i])
        return res
        