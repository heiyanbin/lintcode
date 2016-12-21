/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 14-10-22 06:01
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> d(s1.size()+1,vector<bool>(s2.size()+1));
        for(int i=0;i<=s1.size();++i)
            for(int j=0;j<=s2.size();++j)
                d[i][j]= (i==0 && j==0)||(i>0 && s1[i-1]==s3[i+j-1] && d[i-1][j])||(j>0 && s2[j-1]==s3[i+j-1] && d[i][j-1]);
        return d[s1.size()][s2.size()];
    }
};
