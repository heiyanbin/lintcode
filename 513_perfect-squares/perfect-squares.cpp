/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/perfect-squares
@Language: C++
@Datetime: 16-06-20 16:23
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        vector<int> A;
        for (int i = 1; i * i <= n; ++i) A.push_back(i * i);
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = A[i - 1]; j <= n ; ++j) {
                dp[j] = min(dp[j], dp[j - A[i - 1]] + 1);
            }
        }
        return dp[n];
    }
};