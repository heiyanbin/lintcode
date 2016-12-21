/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/k-sum
@Language: C++
@Datetime: 14-12-23 03:03
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A,int k,int target) {
        // wirte your code here
        vector<vector<vector<int>>> d(A.size()+1,vector<vector<int>>(target+1,vector<int>(k+1,0)));
        for(int i=0;i<=A.size();++i)
            d[i][0][0]=1;
        for(int i=1;i<=A.size();++i)
            for(int j=1;j<=target;++j)
                for(int m=1; m<=min(k,i); ++m)
                    d[i][j][m] = d[i-1][j][m] + (j >= A[i - 1] ? d[i-1][j-A[i-1]][m-1] : 0);
        return d[A.size()][target][k];
    }
};
