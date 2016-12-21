# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/k-sum-ii
@Language: Python
@Datetime: 14-12-19 16:39
'''

class Solution:
    """
    @param A: An integer array.
    @param k: A positive integer (k <= length(A))
    @param target: Integer
    @return a list of lists of integer 
    """
    def kSumII(self, A, k, target):
        # write your code here
        A.sort()
        res=[]
        self.dfs([0]*k,0,A,0,target,res)
        return res
        
    def dfs(self,x,t,A,start,target,res):
        if t==len(x):
            if target==0:
                res.append(x[:])
        else:
            for i in xrange(start,len(A)):
                if A[i]>target:
                    break
                x[t]=A[i]
                self.dfs(x,t+1,A,i+1,target-A[i],res)
                