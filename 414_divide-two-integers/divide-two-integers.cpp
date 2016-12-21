/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/divide-two-integers
@Language: C++
@Datetime: 15-05-25 10:30
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        long long a = abs((long long)dividend), b = abs((long long)divisor), count = 0;
        while (a >= b) {
            long long c = b;
            for (int i = 1; a >= c; i += i, c += c) {
                count += i;
                a -= c;
            }
        }
        count =  (dividend ^ divisor) >> sizeof(int) * 8 - 1 ? -count : count;
        if (count > INT_MAX || count < INT_MIN) return 2147483647;
        return count;
    }
};
