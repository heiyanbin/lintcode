/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/decode-ways
@Language: C++
@Datetime: 16-06-12 07:16
*/

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.empty()) return 0;
        if (s.size() == 1) {
            if (s[0] > '0' && s[0] <= '9') return 1;
            return 0;
        }
        int a = 1, b = 1;
        for (int i = 1; i < s.size(); ++i) {
            int c = 0;
            if (s[i] == '0') {
                if (s[i - 1] != '0' && s[i - 1] < '3') c = a;
                else return 0;
            }
            else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                c = a + b;
            }
            else c = b;
            a = b;
            b = c;
        }
        return b;
    }
};