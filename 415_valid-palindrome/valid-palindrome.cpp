/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 15-05-27 08:11
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
