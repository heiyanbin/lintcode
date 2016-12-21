/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 14-11-24 08:52
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<int> d(n,1);
        for(int i=1;i<m;++i)
            for(int j=1;j<n;++j)
                d[j]= d[j]+ d[j-1];
        return d[n-1];
    }
};

