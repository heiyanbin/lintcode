/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/valid-number
@Language: C++
@Datetime: 15-05-27 11:37
*/

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool isNum = false;
        auto stopAtNonDigit = [&]()->void {
            while (i < n && isdigit(s[i])) {
                isNum = true;
                i++;
            }
        };
        stopAtNonDigit();
        if (i < n && s[i] == '.') i++;
        stopAtNonDigit();
        if (isNum && i < n && s[i] == 'e') {
            i++;
            isNum = false;
            stopAtNonDigit();
        }
        while(i < n && s[i] == ' ') i++;
        return isNum && i == n;
    }
};
