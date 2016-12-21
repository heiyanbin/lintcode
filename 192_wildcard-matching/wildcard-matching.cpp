/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/wildcard-matching
@Language: C++
@Datetime: 15-05-27 07:54
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
		int m = strlen(s), n = strlen(p);
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
		f[0][0] = true;
		for (int j = 1; j <= n; j++)
			if (f[0][j - 1] && p[j - 1] == '*') f[0][j] = true;
			
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
					f[i][j] = f[i - 1][j - 1];
				else if (p[j - 1] == '*' ) {
					f[i][j] = f[i - 1][j] || f[i][j - 1];
				}
			}
		}
		return f[m][n];
	}
};
