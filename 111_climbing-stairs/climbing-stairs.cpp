/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 14-11-20 05:42
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @return: an integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n<=2) return n;
        int f1=1,f2=2;
        for(int i=3;i<=n;i++)
        {
            int f = f1 + f2;
            f1=f2;
            f2=f;
        }
        return f2;
    }
};

