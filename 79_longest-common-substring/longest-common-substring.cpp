/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 14-11-24 10:47
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m=A.size(), n=B.size(), maxLen = 0;
        vector<int> d(n+1);
        for(int i=1;i<=m;++i)
            for(int j=n;j>0;--j)
            {
                d[j]= A[i-1]==B[j-1] ? d[j-1]+1:0;
                maxLen = max( maxLen, d[j]);
            }
        return maxLen;
    }
};

