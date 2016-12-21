/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subarray-sum-ii
@Language: C++
@Datetime: 15-06-01 01:57
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        for (int i = 1; i < A.size(); A[i] = A[i - 1] + A[i], ++i) ;
        int count = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i; j < A.size(); ++j) {
                int sum = A[j] - (i > 0 ? A[i - 1] : 0);
                if (sum >= start && sum <= end) count++;
            }
        }
        return count;
    }
};
