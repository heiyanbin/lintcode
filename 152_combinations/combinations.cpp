/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 14-12-24 07:30
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        vector<int> x(k);
        dfs(x, 0, 1, n, res);
        return res;
    }
    void dfs(vector<int> &x, int t, int start, int n, vector<vector<int>> &res) {
        if (t == x.size())
            res.push_back(x);
        else {
            for (int i = start; i <= n; ++i) {
                x[t] = i;
                dfs(x, t+1, i+1, n, res);
            }
        }
    }
};
