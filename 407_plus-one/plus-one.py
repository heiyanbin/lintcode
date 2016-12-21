# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: Python
@Datetime: 15-05-19 05:30
'''

class Solution:
    # @param {int[]} digits a number represented as an array of digits
    # @return {int[]} the result
    def plusOne(self, digits):
        # Write your code here
        i, carry = len(digits) - 1, 1
        while i >= 0 and carry > 0:
            sum = digits[i] + carry
            digits[i] = sum % 10
            carry = sum / 10
            i -= 1
        
        if carry > 0:
            digits.insert(0, carry)
        
        return digits