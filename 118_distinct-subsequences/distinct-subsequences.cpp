/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 15-04-23 06:50
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int m = S.size(), n = T.size();
        if (m < n) return 0;
        
        vector<int> d(n + 1);
        d[0]=1;
        
        for (int i = 1; i <= S.size(); ++i)
            for (int j = T.size(); j > 0; --j)
                d[j] = S[i-1] == T[j-1] ? d[j-1] + d[j] : d[j];
                
        return d[n];
    }
};

