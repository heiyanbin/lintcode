/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/trapping-rain-water-ii
@Language: C++
@Datetime: 15-08-10 08:53
*/

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        int m = heights.size();
    	if (m == 0) return 0;
    	int n = heights[0].size();
    	if (n == 0) return 0;
    	struct Cell {
    		int i, j, h;
    		Cell() {}
    		Cell(int i, int j, int h) : i(i), j(j), h(h) {}
    		bool operator() (Cell &a, Cell &b) {
    			return a.h > b.h;
    		}
    	};
    	vector<vector<short>> marked(m, vector<short>(n));
    	priority_queue<Cell, vector<Cell>, Cell> q;
    	for (int i = 0; i < m; ++i) {
    		q.push(Cell(i, 0, heights[i][0]));
    		marked[i][0] = 1;
    		q.push(Cell(i, n - 1, heights[i][n - 1]));
    		marked[i][n - 1] = 1;
    	}
    	for (int j = 0; j < n; ++j) {
    		q.push(Cell(0, j, heights[0][j]));
    		marked[0][j] = 1;
    		q.push(Cell(m - 1, j, heights[m - 1][j]));
    		marked[m - 1][j] = 1;
    	}
    	int ans = 0;
    	const pair<int, int> dirs[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    	while (!q.empty()) {
    		auto cur = q.top(); q.pop();
    		for (auto &d : dirs) {
    			int ni = cur.i + d.first, nj = cur.j + d.second;
    			if (ni < m && ni >= 0 && nj < n && nj >= 0 && marked[ni][nj] == 0) {
    				q.push(Cell(ni, nj, max(cur.h, heights[ni][nj])));
    				marked[ni][nj] = 1;
    				ans += max(0, cur.h - heights[ni][nj]);
    			}
    		}
    	}
    	return ans;
    }
};
