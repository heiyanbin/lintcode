/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: Java
@Datetime: 15-02-28 06:27
*/

class Solution {
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    public static int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a ^ b, count  = 0;
        for (; c != 0; count ++)  c = (c - 1) & c;
        return count;
    }
};

