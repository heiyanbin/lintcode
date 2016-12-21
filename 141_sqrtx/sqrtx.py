# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: Python
@Datetime: 14-12-12 00:09
'''

class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        a, b= 1, x
        while(a<=b):
            m = (a+b)/2
            m1= x/m
            if(m==m1): 
                return m
            elif(m>m1):
                b=m-1
            else:
                a=m+1
        return b