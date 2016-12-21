# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-colors
@Language: Python
@Datetime: 14-12-13 12:36
'''

class Solution:
    """
    @param nums: A list of integer which is 0, 1 or 2 
    @return: nothing
    """
    def sortColors(self, nums):
        # write your code here
        n = len(nums)
        i, j, k = -1, 0, n
        while j<k:
            if nums[j]== 0:
                i+=1
                nums[i],nums[j] = nums[j],nums[i]
                j+=1
            elif nums[j]==2:
                k-=1
                nums[k],nums[j] = nums[j],nums[k]
            else:
                j+=1