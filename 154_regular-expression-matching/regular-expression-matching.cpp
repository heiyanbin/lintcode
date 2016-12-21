/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/regular-expression-matching
@Language: C++
@Datetime: 14-12-24 14:04
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if (*p == 0) return *s == 0;
        if (*(p + 1) != '*') 
            return (*s == *p || *p == '.' && *s != 0) && isMatch(s+1, p+1);
        else {
            while (*s == *p || *p == '.' && *s != 0) {
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
};
