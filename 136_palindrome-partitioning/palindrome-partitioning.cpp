/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: C++
@Datetime: 14-12-08 04:03
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<string> path;
        vector<vector<string>> res;
        dfs(s,0,path,res);
        return res;
    }
    void dfs(string &s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        if(start==s.size())
            res.push_back(path);
        for(int i=start;i<s.size();++i)
            if(isPal(s,start,i))
            {
                path.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,path,res);
                path.pop_back();
            }
    }
    bool isPal(string &s,int start, int end)
    {
        for(int L=start, R=end;L<R;L++,R--)
            if(s[L]!=s[R])
                return false;
        return true;
    }
};
