/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 14-11-25 13:46
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        // write your code here
        size_t len =0;
        for(auto &e : dict)
            len = max(len, e.size());
        
        vector<int> d(s.size()+1);
        d[0] = true;
        for(int i=1;i<=s.size();++i)
            for(int j=i-1;j>=0 && i-j<=len;--j)
                if(dict.find(s.substr(j,i-j))!=dict.end()&&d[j])
                {
                    d[i]=true;
                    break;
                }
         return d[s.size()];           
    }
};
