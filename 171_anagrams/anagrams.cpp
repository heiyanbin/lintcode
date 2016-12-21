/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 15-01-06 09:29
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> m;
        for (string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<string> res;
        for (auto &e : m) {
            if (e.second.size() > 1) 
                for (string &s : e.second)
                    res.push_back(s);
        }
        return res;
    }
};

