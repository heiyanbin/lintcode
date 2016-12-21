# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: Python
@Datetime: 15-05-11 09:31
'''

class Solution:
    # @param heights: a list of integers
    # @return: an integer
    def maxArea(self, heights):
        # write your code here
        i, j, mostWater = 0, len(heights) - 1, 0
        while i < j:
            mostWater = max(mostWater, (j - i) * min(heights[i], heights[j]))
            if heights[i] < heights[j]: i += 1
            else: j -= 1
        return mostWater
