/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 14-12-08 06:32
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<int> d(m+1);
        for(int i=1;i<=A.size();++i)
            for(int j=m;j>=A[i-1];--j)
                    d[j]=max(d[j], d[j-A[i-1]]+A[i-1]);
        return d[m];
    }
};
