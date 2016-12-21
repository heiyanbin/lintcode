/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/kth-smallest-number-in-sorted-matrix
@Language: C++
@Datetime: 15-06-01 04:53
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
		struct P {
			int i, j, v;
			bool operator()(P &a, P &b) { return  a.v > b.v; }
			P(int i, int j, int v) : i(i), j(j), v(v) {}
			P(){}
		};
		priority_queue<P, vector<P>, P> q;
		vector<vector<int>> marked(matrix.size(), vector<int>(matrix[0].size()));
		q.push(P(0, 0, matrix[0][0]));
		marked[0][0] = true;
		while (!q.empty()) {
			int i = q.top().i, j = q.top().j, v = q.top().v;
			q.pop();
			k--;
			if (k == 0) return v;
			if (i + 1 < matrix.size() && !marked[i + 1][j]) {
				marked[i + 1][j] = true;
				q.push(P(i + 1, j, matrix[i + 1][j]));
			}
			if (j + 1 < matrix[i].size() && !marked[i][j + 1]) {
				marked[i][j + 1] = true;
				q.push(P(i, j + 1, matrix[i][j + 1]));
			}
		}
		return INT_MAX;
    }
};
