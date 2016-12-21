# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/3sum
@Language: Python
@Datetime: 14-12-15 16:43
'''

class Solution:
    """
    @param numbersbers : Give an array numbersbers of n integer
    @return : Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        numbers.sort()
        n, res =  len(numbers), []
        for i in xrange(n-2):
            if i>0 and numbers[i]==numbers[i-1]:
                continue
            l, r = i+1, n-1
            while l<r:
                sum = numbers[i]+numbers[l]+numbers[r]
                if sum == 0:
                    res.append([numbers[i],numbers[l],numbers[r]])
                    l+=1
                    while l<r and numbers[l]==numbers[l-1]:
                        l+=1
                    r-=1
                    while l<r and numbers[r]==numbers[r+1]:
                        r-=1
                elif sum < 0:
                    l+=1
                else:
                    r-=1
        return res
        
