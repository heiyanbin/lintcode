/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 15-06-01 05:57
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int i = s.size() - 1;
        for (; i >= 0 && s[i] == ' '; --i) ;
        if (i < 0) return 0;
        for (int j = i - 1; j >= 0; --j) {
            if (s[j] ==' ') return i - j;
        }
        return  i + 1;
    }
};
