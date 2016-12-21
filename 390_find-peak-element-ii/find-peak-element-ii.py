# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-peak-element-ii
@Language: Python
@Datetime: 15-05-26 10:32
'''

class Solution:
    #@param A: An list of list integer 
    #@return: The index of position is a list of integer, for example [2,2]
    def findPeakII(self, A):
        # write your code here
        i, j = 1, 1
        while i < len(A) and j < len(A[i]):
            if A[i][j] > A[i + 1][j] and A[i][j] > A[i][j + 1]: return i, j
            elif A[i + 1][j] > A[i][j + 1]: i += 1
            else: j += 1
        return -1, -1
