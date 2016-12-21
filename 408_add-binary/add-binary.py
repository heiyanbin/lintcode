# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: Python
@Datetime: 15-05-19 04:52
'''

class Solution:
    # @param {string} a a number
    # @param {string} b a number
    # @return {string} the result
    def addBinary(self, a, b):
        # Write your code here
        res, i, j, carry = [], len(a) - 1, len(b) - 1, 0
        while i >= 0 or j >= 0 or carry > 0:
            v1, v2 = 0, 0
            if i >= 0: v1 = int(a[i])
            if j >= 0: v2 = int(b[j])
            sum = v1 + v2 + carry
            res.append(str(sum % 2))
            i, j, carry = i - 1, j - 1, sum / 2 
        
        return ''.join(reversed(res))
        
        
