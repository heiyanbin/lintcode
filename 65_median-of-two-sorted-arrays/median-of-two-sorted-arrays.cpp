/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/median-of-two-sorted-arrays
@Language: C++
@Datetime: 15-01-03 13:09
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int l = A.size()+B.size();
        if((l&1)==1) return select(A,0,A.size()-1,B,0,B.size()-1,l/2+1);
        return 0.5*(select(A,0,A.size()-1,B,0,B.size()-1,l/2)+select(A,0,A.size()-1,B,0,B.size()-1,l/2+1));
    }
    int select(vector<int> &A, int p, int q, vector<int> &B, int r, int s, int k)
    {
        int m = q-p+1, n=s-r+1;
        if(m>n) return select(B,r,s,A,p,q,k);
        if(m==0) return B[r+k-1];
        if(k==1) return min(A[p],B[r]);
        int i = min(k/2,m), j= k-i;
        if(A[p+i-1]< B[r+j-1]) return select(A,p+i,q,B,r,r+j-1,j);
        return select(A,p,p+i-1,B,r+j,s,i);
    }
};

