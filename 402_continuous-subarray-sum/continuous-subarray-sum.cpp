/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/continuous-subarray-sum
@Language: C++
@Datetime: 15-06-02 23:39
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        if (A.empty()) return {};
        int f = A[0], maxSum = A[0], curStart = 0, maxStart = 0, maxEnd = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (f + A[i] > A[i]) {
                f = f + A[i];
            } else {
                f = A[i];
                curStart = i;
            }
            if (f > maxSum) {
                maxSum = f;
                maxStart = curStart;
                maxEnd = i;
            }
        }
        return {maxStart, maxEnd};
    }
};
