/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence-ii
@Language: C++
@Datetime: 15-05-27 06:42
*/

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int m = A.size(), n = A[0].size(), maxLen = 0;
  
        vector<vector<int>> f(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
           if (f[i][j] > 0) return f[i][j];
           vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
           for (auto &d : directions) {
               int newI = i + d.first, newJ = j + d.second;
               if (newI < 0 || newI == m || newJ < 0 || newJ == n || A[i][j] >= A[newI][newJ]) continue;
               f[i][j] = max(f[i][j], dfs(newI, newJ) + 1);
           }
           if (f[i][j] < 0) f[i][j] = 1;
           return f[i][j];
        };
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                maxLen = max(maxLen, dfs(i, j));
        return maxLen;
    }
};
