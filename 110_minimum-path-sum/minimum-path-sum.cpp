/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 14-11-20 04:56
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i||j)
                    if(i==0)
                        grid[i][j]=grid[i][j-1]+grid[i][j];
                    else if(j==0)
                        grid[i][j]=grid[i-1][j]+grid[i][j];
                    else
                        grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        return grid[m-1][n-1];
    }
};

