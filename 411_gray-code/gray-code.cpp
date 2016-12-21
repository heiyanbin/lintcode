/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/gray-code
@Language: C++
@Datetime: 15-05-24 22:18
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        if (n < 1) return vector<int>{0};
        vector<int> res{0, 1};
        for (int i = 2; i <= n; i ++) {
            int sz = res.size();
            for (int k = sz - 1; k >= 0; k--) {
                res.push_back((1 <<  (i - 1)) + res[k]);
            }
        }
        return res;
    }
};
