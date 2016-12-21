# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-size-subarray-sum
@Language: Python
@Datetime: 15-05-27 01:29
'''

class Solution:
     # @param nums: a list of integers
     # @param s: an integer
     # @return: an integer representing the minimum size of subarray
    def minimumSize(self, nums, s):
        # write your code here
        i, sum, minLen = 0, 0, len(nums) + 1
        for j in xrange(len(nums)):
            sum += nums[j]
            while sum >= s:
                minLen = min(minLen, j - i + 1)
                sum -= nums[i]
                i += 1
        if minLen > len(nums): return 0
        else: return minLen
            
            
