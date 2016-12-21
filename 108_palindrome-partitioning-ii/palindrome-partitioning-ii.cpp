/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning-ii
@Language: C++
@Datetime: 15-04-23 01:22
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        vector<vector<bool>> par(s.size(), vector<bool>(s.size()));
        vector<int> d(s.size());
        for (int i = 0; i < s.size(); ++i) {
            d[i] = i;
            for (int j = i; j >= 0; --j) {
                if (s[i] == s[j] && (i - j < 2 || par[j + 1][i - 1])) {
                    par[j][i] = true;
                    d[i] = j == 0 ? 0 : min(d[i], d[j - 1] + 1);
                }
            }
        }
        return d[s.size() - 1];
    }
};


