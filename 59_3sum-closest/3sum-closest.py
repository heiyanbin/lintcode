# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: Python
@Datetime: 14-12-15 16:26
'''

class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target : An integer
    @return : return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
    # write your code here
        n, mindiff, res = len(numbers), sys.maxint, 0
        numbers.sort()
        for i in xrange(n-2):
            if i>0 and numbers[i]==numbers[i-1]:
                continue
            l,r=i+1,n-1
            while l<r:
                sum = numbers[i]+numbers[l]+numbers[r]
                if abs(sum-target)<mindiff:
                    res = sum
                    mindiff = min(mindiff, abs(sum-target))
                if sum<target:
                    l+=1
                elif sum>target:
                    r-=1
                else:
                    return target
        return res
        