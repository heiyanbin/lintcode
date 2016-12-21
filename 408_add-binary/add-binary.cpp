/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 15-05-19 04:42
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        for (; i >= 0 && j >= 0; i--, j--) {
            int sum = a[i] - '0' + b[j] - '0' + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        
        for (; i >= 0; i--) {
            int sum = a[i] - '0'  + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        
        for (; j >= 0; j--) {
            int sum = b[j] - '0'  + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        
        if (carry > 0)
            res.push_back(carry + '0');
            
        return string(res.rbegin(), res.rend());
    }
};
