/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 15-07-07 08:29
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int n = 0;
        for (int &e : A) n ^= e;
        n = n - (n & (n - 1)); //calcualate a mask, only keep the lowest "1"
        
        int a = 0, b = 0;
        for (int &e : A) {
            if (e & n) a ^= e;
            else b ^= e;
        }
        return {a, b};
    }
};
