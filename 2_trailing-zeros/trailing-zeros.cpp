/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 15-01-08 16:33
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long count = 0;
        for (long long i = 5; i < n; count += n / i, i *= 5);
        return count;
    }
};

