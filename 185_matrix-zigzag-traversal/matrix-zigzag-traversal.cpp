/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/matrix-zigzag-traversal
@Language: C++
@Datetime: 15-05-20 06:26
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
		// write your code here
		vector<int> res;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		if (n == 0) return res;
		
		for (int k = 0, x, y; k < m + n - 1; k++) {
		    if (k < m) {
		        y = 0;
		        x = k;
		    } else {
		        x = m - 1;
		        y = k - m + 1;
		    }
		    vector<int> level;
		    while (x >= 0 && x < m && y >= 0 && y < n) {
		        level.push_back(matrix[x][y]);
		        x--;
		        y++;
		    }
		    if (k % 2) reverse(level.begin(), level.end());
		    copy(level.begin(), level.end(), back_inserter(res));
		}
		return res;
	}
};
