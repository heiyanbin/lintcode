/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 15-03-31 03:36
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int i = 0;
        while (i < str.size() && str[i] == ' ') i ++;
        if (i == str.size()) return 0;
        bool negative = false;
        if (str[i] == '-') {
            negative = true; 
            i ++;
        }
        else if (str[i] == '+') i ++;
        
        long long value = 0;
        for (; i < str.size(); ++ i) {
            if (!isdigit(str[i])) break;
            value = value * 10 + str[i] - '0';
            if (!negative && value > INT_MAX) return INT_MAX;
            if (negative && -value < INT_MIN) return INT_MIN;
        }
        
        return negative ? -value : value;
    }
};
