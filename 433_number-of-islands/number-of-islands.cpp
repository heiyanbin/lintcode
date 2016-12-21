/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 15-06-28 07:29
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        const pair<int,int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<void(int, int j)> dfs = [&](int i, int j) {
            if (i < 0  || i >= grid.size() || j < 0 || j >= grid[i].size() || !grid[i][j]) return;
            grid[i][j] = false;
            for (auto & d : dirs) dfs(i + d.first, j + d.second);
        };
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    dfs(i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
