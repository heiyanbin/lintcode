/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/continuous-subarray-sum-ii
@Language: C++
@Datetime: 15-06-03 01:00
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        if (A.empty()) return {};
        auto help = [&](int l, int r, function<bool(int, int)> cmp) {
            int curSum = A[l], curStart = l, maxSum = A[0], maxStart = l, maxEnd = l, total = A[l];
            for (int i = l + 1; i <= r; ++i) {
                if (cmp(curSum + A[i], A[i])) {
                    curSum += A[i];
                } else {
                    curSum = A[i];
                    curStart = i;
                }
                if (cmp(curSum, maxSum)) {
                    maxSum = curSum;
                    maxStart = curStart;
                    maxEnd = i;
                }
                total += A[i];
            }
            return vector<int>{maxSum, maxStart, maxEnd, total};
        };
        auto r1 = help(0, A.size() - 1, [](int a, int b) {return a > b; });
        if (A.size() <= 2) return {r1[1], r1[2]};
        auto r2 = help(1, A.size() - 2, [](int a, int b) {return a < b; });
        if (r1[0] > r1[3] - r2[0]) return {r1[1], r1[2]};
        return {r2[2] + 1, r2[1] - 1};
    }
};
