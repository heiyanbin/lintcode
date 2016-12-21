/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 14-10-21 16:36
*/

#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        vector<int> d(B.size()+1),e(B.size()+1);
        for(int i=1;i<=A.size();++i)
        {
            for(int j=1;j<=B.size();++j)
            {
                if(A[i-1]==B[j-1])
                    e[j]=d[j-1]+1;
                else
                    e[j]=max(e[j-1],d[j]);
            }
            d=e;
        }
        return d[B.size()];
    }
};

