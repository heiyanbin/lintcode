/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 15-02-03 02:50
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        string res;
        for (int d = 0, pos = -1; d < A.size() - k; d++) {
            int min_digit = 10;
            for (int i = pos + 1; i <= k + d; i++) {
                if (A[i] - '0' < min_digit) {
                    min_digit = A[i] - '0';
                    pos = i;
                }
            }
            if (res.empty() && min_digit == 0) continue;
            res.push_back(min_digit + '0');
        }
        return res;
    }
};

