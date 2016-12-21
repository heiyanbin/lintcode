# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/set-matrix-zeroes
@Language: Python
@Datetime: 14-12-26 15:44
'''

class Solution:
    """
    @param matrix: A list of lists of integers
    @return: Nothing
    """
    def setZeroes(self, matrix):
        # write your code here
        if len(matrix) == 0: return 
        row, col = [0] * len(matrix), [0] * len(matrix[0])
        for i in xrange(0, len(matrix)):
            for j in xrange(0, len(matrix[i])):
                if matrix[i][j] == 0:
                    row[i], col[j] = 1, 1
        for i in xrange(0, len(matrix)):
            for j in xrange(0, len(matrix[i])):
                if row[i] == 1 or col[j] == 1:
                    matrix[i][j] = 0