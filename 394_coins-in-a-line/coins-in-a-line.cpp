/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/coins-in-a-line
@Language: C++
@Datetime: 15-05-24 22:31
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        if (n <= 0) return false;
        return !(n % 3 == 0);
    }
};
