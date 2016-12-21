/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/restore-ip-addresses
@Language: C++
@Datetime: 16-06-12 06:41
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<int> path;
        vector<string> ans;
        dfs(0, 0, s, path, ans);
        return ans;
    }

private:
    void dfs(int i, int t, string &s, vector<int> &path, vector<string> &ans) {
        if (t == 4) {
            if (i == s.size()) {
                string tmp;
                for (int j = 0; j < path.size(); ++j) {
                    tmp.append(to_string(path[j]));
                    if (j < 3) {
                        tmp.push_back('.');
                    }
                }
                ans.push_back(tmp);
            }
        }
        else {
            for (int k = 0; k < 3; ++k) {
                int x = 0;
                if (i + k >= s.size() || (x = stoi(s.substr(i, k + 1))) > 255) break;
                path.push_back(x);
                dfs(i + k + 1, t + 1, s, path, ans);
                path.pop_back();
                if (s[i] == '0') break;
            }
        }
    }
};