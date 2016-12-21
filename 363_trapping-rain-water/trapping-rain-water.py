# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: Python
@Datetime: 15-05-05 01:25
'''

class Solution:
    # @param heights: a list of integers
    # @return: a integer
    def trapRainWater(self, heights):
        # write your code here
        n = len(heights)
        if n == 0: return 0
        leftHighest = [0] * n
        for i in xrange(1, n):
            leftHighest[i] = max(leftHighest[i - 1], heights[i - 1])
        
        rightHighest, area = 0, 0
        for i in xrange(n - 2, -1, -1):
            rightHighest = max(rightHighest, heights[i + 1])
            h = min(leftHighest[i], rightHighest) 
            if h > heights[i]:
                area += h - heights[i]
        
        return area
            
            

