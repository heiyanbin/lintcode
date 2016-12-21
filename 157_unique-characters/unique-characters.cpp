/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 14-12-30 02:25
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        vector<bool> charset(256, false);
        for (char c : str) {
            if (charset[c]) return false;
            charset[c] = true;
        }
        return true;
    }
};
