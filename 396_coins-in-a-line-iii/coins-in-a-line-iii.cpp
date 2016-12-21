/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/coins-in-a-line-iii
@Language: C++
@Datetime: 15-05-25 07:53
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        vector<int> preSum {0};
        for (int v : values) preSum.push_back(preSum.back() + v);
        
        int n = values.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                f[i][j] = j - i < 2 ? max(values[i], values[j]) :
                max(values[i] + preSum[j + 1] - preSum[i + 1] - f[i + 1][j],
                    values[j] + preSum[j] - preSum[i] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] > preSum[n] - f[0][n - 1];
    }
};
