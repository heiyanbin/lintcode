/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 15-12-14 06:37
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / myPow(x, -n);
        double ans = 1.0;
        for (; n != 0; n >>= 1) {
            if (n & 1) ans *= x;
            x *= x;
        }
        return ans;
    }
};