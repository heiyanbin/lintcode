/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/letter-combinations-of-a-phone-number
@Language: C++
@Datetime: 15-06-01 08:52
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        if (digits.empty()) return {};
		string m[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res;
		string path;
		function<void(int)> dfs = [&](int t)->void {
			if (t == digits.size()) res.push_back(path);
			else {
				for (char c : m[digits[t] - '0']) {
					path.push_back(c);
					dfs(t + 1);
					path.pop_back();
				}
			}
		};
		dfs(0);
		return res;
	}
};
