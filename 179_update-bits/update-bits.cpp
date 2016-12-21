/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: C++
@Datetime: 15-03-11 03:27
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        
        //mark the related bits in n to 0
        n = n & ~(((((long long)1) << (j - i + 1)) - 1) << i);
     
        //result
        return n | (m << i);
    }
};
