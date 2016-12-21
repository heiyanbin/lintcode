/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-06-12 04:03
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if (num <= 0) return false;
        for (; (num & 1) == 0;) {
            num = num / 2;
        }
        
        for (;  (num % 3) == 0; ) {
            num = num / 3;
        }
        
        for (; num % 5 == 0; ) {
            num /= 5;
        }
        
        return num == 1;
    }
};