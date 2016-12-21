/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 15-05-24 03:55
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        while (num) {
            num = num & (num - 1);
            count ++;
        }
        return count;
    }
};
