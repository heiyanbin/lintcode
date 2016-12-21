# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-colors-ii
@Language: Python
@Datetime: 14-12-22 04:15
'''

class Solution:
    """
    @param colors: A list of integer
    @param k: An integer
    @return: nothing
    """
    def sortColors2(self, colors, k):
        # write your code here
        for i in xrange(0, len(colors)):
            while colors[i] > 0:
                bucket = colors[i]-1
                if colors[bucket] <= 0:
                    colors[bucket] -= 1
                    colors[i] = 0
                else:
                    colors[i] = colors[bucket]
                    colors[bucket] = -1

        j = len(colors)-1
        while colors[j] == 0: j -= 1
        i = len(colors) - 1
        while j >= 0:
            cnt = -colors[j]
            while cnt > 0:
                colors[i] = j + 1
                i -= 1
                cnt -= 1
            j -= 1
