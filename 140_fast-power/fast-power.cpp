/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 14-12-11 04:47
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(b==0 && n==1) return 0;
        return fp(a, b, n);
    }
    int fp (long long a, long long b, int n) {
        long long res = 1;
        while(b>0) {
            if(b&1) res = (res * a) % n;
            a=(a*a) % n;
            b>>=1;
        }
        return res;
    }
    
};
