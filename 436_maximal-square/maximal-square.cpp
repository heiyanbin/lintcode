/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximal-square
@Language: C++
@Datetime: 15-07-06 11:08
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> f(matrix.size(), vector<int>(matrix[0].size()));
        int maxSize = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) f[i][j] = 0;
                else {
                    int up = i > 0 ? f[i - 1][j] : 0;
                    int left = j > 0 ? f[i][j - 1] : 0;
                    int left_up = (i > 0  && j > 0) ? f[i - 1][j - 1] : 0;
                    f[i][j] = min(min(left, up), left_up) + 1;
                }
                if (f[i][j] > maxSize) maxSize = f[i][j];
            }
        }
        return maxSize * maxSize;
    }
};
