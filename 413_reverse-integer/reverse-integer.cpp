/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 15-05-24 11:49
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        int value = 0;
        while (n != 0) {
            if (value > INT_MAX / 10 || value < INT_MIN / 10) return 0;
            if (value == INT_MAX / 10 && value % 10 > INT_MAX % 10 ||
                value == INT_MIN / 10 && abs(value % 10) > abs(INT_MIN % 10))
                return 0;
            value = value * 10 + n % 10;
            n /= 10;
        }
        return value;
    }
};
