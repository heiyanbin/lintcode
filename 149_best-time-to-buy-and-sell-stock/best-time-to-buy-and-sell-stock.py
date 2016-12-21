# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: Python
@Datetime: 15-01-21 15:55
'''

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        if len(prices) <= 1: return 0
        low, res = prices[0], 0
        for i in range(1, len(prices)):
            low = min(low, prices[i])
            res = max(res, prices[i] - low)
        return res
            
            