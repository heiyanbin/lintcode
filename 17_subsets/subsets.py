# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subsets
@Language: Python
@Datetime: 14-12-18 07:06
'''

class Solution:
    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def subsets(self, S):
        # write your code here
        S.sort()
        self.dfs([0]*len(S),0,S,0)
        return self.res
    def dfs(self,x,t,s,start):
        self.res.append(x[:t])
        for i in xrange(start,len(s)):
            x[t]= s[i]
            self.dfs(x,t+1,s,i+1)
    res=[]