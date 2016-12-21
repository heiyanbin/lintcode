/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 14-12-24 08:04
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        vector<int> x;
        vector<vector<int>> res;
        dfs(x, num, 0, target, res);
        return res;
    }
    void dfs(vector<int> &x, vector<int> &num, int start, int target, vector<vector<int>> &res) {
        if (target == 0)
            res.push_back(x);
        else {
            for (int i = start; i < num.size(); ++i) {
                if (num[i] > target) break;
                if (i > start && num[i] == num[i-1]) continue;
                x.push_back(num[i]);
                dfs(x, num, i + 1, target - num[i], res);
                x.pop_back();
            }
        }
    }
};
