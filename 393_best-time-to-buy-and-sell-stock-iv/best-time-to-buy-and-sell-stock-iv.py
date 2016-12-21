# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iv
@Language: Python
@Datetime: 15-05-26 09:36
'''

class Solution:
    """
    @param k: an integer
    @param prices: a list of integer
    @return: an integer which is maximum profit
    """
    def maxProfit(self, k, prices):
        # write your code here
        n = len(prices)
        if k < 1 or n < 2: return 0
        if k >= n / 2:
            sum = 0
            for i in xrange(1, n):
                if prices[i] > prices[i - 1]:
                    sum += prices[i] - prices[i - 1]
            return sum
        f, g = [[0] * (k + 1) for i in [0, 1]], [[0] * (k + 1) for i in [0, 1]]
        for i in xrange(1, n):
            for j in xrange(1, k + 1):
                f[i % 2][j] = max(f[(i - 1) % 2][j], g[(i - 1) % 2][j - 1]) + prices[i] - prices[i - 1]
                g[i % 2][j] = max(f[(i - 1) % 2][j], g[(i - 1) % 2][j])
        
        return max(f[(n - 1) % 2][k], g[(n - 1) % 2][k])