/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: C++
@Datetime: 15-12-10 02:21
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, int, string)> dfs = [&](int t, int leftCount, int rightCount, string path) -> void {
            if (t == 2*n) ans.push_back(path);
            else {
                if (leftCount < n) dfs(t + 1, leftCount + 1, rightCount, path + '(');
                if (rightCount < leftCount) dfs(t + 1, leftCount, rightCount + 1, path + ')');
            }
        };
        dfs(0, 0, 0, "");
        return ans;
    }
};