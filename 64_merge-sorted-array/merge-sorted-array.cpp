/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 14-11-11 04:27
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        for(int k= m+n-1,i=m-1,j=n-1;j>=0;k--)
        {
            if(B[j]>A[i])
                A[k]=B[j--];
            else
                A[k]=A[i--];
        }
    }
};
