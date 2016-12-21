/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 15-05-28 06:49
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string s = "1";
		if (n == 1) return s;
		for (int i = 2; i <= n; i++) {
			string t;
			for (int j = 0; j < s.size(); j++) {
				int count = 1;
				while (j + 1 < s.size() && s[j + 1] == s[j]) {
					count++;
					j++;
				}
				t.push_back(count + '0');
				t.push_back(s[j]);
			}
			s = t;
		}
		return s;
    }
};
