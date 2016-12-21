/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 15-03-30 05:01
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size() ; ++ i) 
            for (int k = 1; k < strs.size(); ++ k) 
                if (strs[k][i] != strs[0][i]) return strs[0].substr(0, i);
        return strs[0];
    }
};
