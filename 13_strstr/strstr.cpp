/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 14-12-28 13:30
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (!source||!target) return -1;
        if (!source[0] && !target[0]) return 0;
        for (int i = 0; source[i]; ++i) {
            int j = 0;
            for (; target[j] && source[i+j] && source[i+j] == target[j]; ++j);
            if (!target[j]) return i;
            if (!source[i+j]) return -1;
        }
        return -1;
    }
};

