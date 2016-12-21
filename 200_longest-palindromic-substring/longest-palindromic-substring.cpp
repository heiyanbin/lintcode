/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-palindromic-substring
@Language: C++
@Datetime: 15-05-25 04:36
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int maxLen = 0,  start = -1, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int k = 0; i - k >= 0 && i + k < n && s[i - k] == s[i + k]; k++) {
                if (k * 2 + 1 > maxLen) {
                    maxLen = k * 2 + 1;
                    start = i - k;
                }
            }
            for (int k = 0; i - k >= 0 && i + 1 + k < n && s[i - k] == s[i + 1 + k]; k++) {
                if (k * 2 + 2 > maxLen) {
                    maxLen = k * 2 + 2;
                    start = i - k;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
