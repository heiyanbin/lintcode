/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/heapify
@Language: C++
@Datetime: 14-12-03 14:19
*/

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for(int i=A.size()/2-1;i>=0;i--)
            sink(A,i);
    }
    void sink(vector<int> &A, int i)
    {
        int n = A.size();
        while(2*i+1<n)
        {
            int j= 2*i+1;
            if(j+1<n && A[j+1]<A[j]) j++;
            if(A[i]<=A[j]) break;
            swap(A[i],A[j]);
            i=j;
        }
    }
};
