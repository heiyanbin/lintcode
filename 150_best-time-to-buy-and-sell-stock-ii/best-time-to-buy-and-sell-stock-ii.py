# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-ii
@Language: Python
@Datetime: 14-12-12 01:13
'''

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        if len(prices)<=1:
            return 0
        total =0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                total += prices[i]-prices[i-1]
        return total