/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 15-05-24 04:06
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n < 1) return 0;
        if (n <= 2) return n - 1;
        int a = 0, b = 1;
        for (int i = 3; i <= n; i ++) {
            int f = a + b;
            a = b;
            b = f;
        }
        return b;
    }
};

