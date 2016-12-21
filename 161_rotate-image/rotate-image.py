# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/rotate-image
@Language: Python
@Datetime: 14-12-26 16:18
'''

class Solution:
    """
    @param matrix: A list of lists of integers
    @return: Nothing
    """
    def rotate(self, matrix):
        # write your code here
        if matrix == None or len(matrix) == 0: return
        n = len(matrix)
        start, end = 0, n - 1
        while start < end:
            for j in xrange(0, n):
                matrix[start][j], matrix[end][j] = matrix[end][j], matrix[start][j]
            start += 1
            end -= 1
        for i in xrange(0, n):
            for j in xrange(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
