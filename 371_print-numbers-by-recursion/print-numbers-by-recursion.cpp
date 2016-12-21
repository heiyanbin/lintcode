/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 15-05-18 06:03
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> res(1, 0);
        print(0, n, res);
        return  vector<int>(res.begin() + 1, res.end());
    }
    
    void print(int i, int n, vector<int> &res) {
        if (i == n) return;
        
        int sz = res.size(), base = pow(10, i);
        for (int k = 1; k <= 9; k++) {
            for (int j = 0; j < sz; j++)
                res.push_back(base * k + res[j]);
        }
        
        print(i + 1, n, res);
    }
};
