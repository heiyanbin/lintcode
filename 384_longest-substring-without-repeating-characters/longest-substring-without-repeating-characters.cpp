/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-substring-without-repeating-characters
@Language: C++
@Datetime: 15-05-11 10:25
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        vector<int> charSet(256, -1);
        int maxLen = 0;
        for (int start = 0, i = 0; i < s.size(); i++) {
            if (charSet[s[i]] >= start) start = charSet[s[i]] + 1;
            charSet[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
