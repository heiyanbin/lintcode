/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers
@Language: C++
@Datetime: 15-05-29 01:30
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        int i = 0, j = 0, n = A.size();
        for ( ; j < n; ++j) 
            if (A[j] < 0 )  swap(A[i++], A[j]);
        if(i > n - i) reverse(A.begin(), A.end());
        for (i = (i > n - i ? 0 : 1), j = 1 ^ i; i < n && j < n;  ) {
            while ( i < n && A[i] < 0) i += 2;
            while ( j < n && A[j] > 0) j += 2;
            if (i < n && j < n) swap (A[i], A[j]);
        }
        return A;
    }
};
