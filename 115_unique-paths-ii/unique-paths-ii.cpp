/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 15-01-12 16:24
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> d(n);
        d[0] = 1;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                d[j] = obstacleGrid[i][j] ? 0 : ((j > 0 ? d[j-1] : 0) + d[j]);
        return d[n-1];
    }
};
