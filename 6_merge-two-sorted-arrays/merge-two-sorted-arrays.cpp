/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 15-03-11 07:30
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> C(A.size() + B.size());
        for (int i = 0, j = 0, k = 0; k < C.size(); ++ k) {
            if (i == A.size()) C[k] = B[j ++];
            else if(j == B.size()) C[k] = A[i ++];
            else C[k] = A[i] <= B[j] ? A[i ++] : B[j ++];
        }
        return C;
    }
};
