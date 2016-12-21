/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/post-office-problem
@Language: C++
@Datetime: 15-08-18 09:44
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        int n = A.size();
        if (n == 0 || k >= n) return 0;
        sort(begin(A), end(A));
        vector<vector<int>> dis(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int m = i + (j - i) / 2;
                for (int k = i; k <= j; ++k)
                    dis[i][j] += abs(A[k] - A[m]);
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(k));
        for (int i = 0; i < n; ++i) dp[i][0] = dis[0][i];
        
        for (int l = 1; l < k; ++l) {
            for (int i = l; i < n; ++i) {
                dp[i][l] = INT_MAX;
                for (int j = 0; j < i; ++j) {
                    dp[i][l] = min(dp[i][l], dp[j][l - 1] + dis[j + 1][i]);
                }
            }
        }
        
        return dp[n - 1][k - 1];
    }
};
