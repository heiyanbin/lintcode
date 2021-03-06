/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: C++
@Datetime: 14-12-11 01:43
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if(n==0) return false;
        return (n & (n-1)) == 0;
    }
};
