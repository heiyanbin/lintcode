/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: C++
@Datetime: 14-12-08 06:30
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> d(m+1);
        for(int i=1;i<=A.size();++i)
            for(int j=m;j>=A[i-1];--j)
                d[j]= max(d[j],d[j-A[i-1]]+V[i-1]);
        return d[m];
    }
};
