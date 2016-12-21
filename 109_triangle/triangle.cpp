/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 14-11-20 16:36
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if(triangle.empty()) return 0;
        for(int i=triangle.size()-2;i>=0;--i)
            for(int j=0;j<=i;++j)
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        return triangle[0][0];
    }
};

