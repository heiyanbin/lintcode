/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/submatrix-sum
@Language: C++
@Datetime: 15-06-02 17:21
*/

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> colPreSum = matrix;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colPreSum[i][j] += colPreSum[i - 1][j];
            }
        }
        for (int a = 0; a < m ; ++a) {
            for (int b = a; b < m; ++b) {
                map<int, int> m;
                m[0] = -1;
                int rowPreSum = 0;
                for (int j = 0; j < n; ++j) {
                    int cur = colPreSum[b][j] - (a > 0 ? colPreSum[a - 1][j] : 0);
                    rowPreSum += cur;
                    auto it = m.find(rowPreSum);
                    if (it == m.end()) m[rowPreSum] = j;
                    else return {{a, it->second + 1}, {b, j}};
                }
            }
        }
        return {};
    }
};
