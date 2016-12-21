/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/strstr
@Language: Java
@Datetime: 15-01-22 03:22
*/

class Solution {
    /**
     * Returns a index to the first occurrence of target in source, or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    public int strStr(String source, String target) {
        if (source == null || target == null) return -1;
        if (source.length() == 0 && target.length() == 0) return 0;
        for (int i = 0; i <= source.length() - target.length(); ++i) {
            int j = 0;
            for (; j < target.length(); ++j) {
                if (source.charAt(i + j) != target.charAt(j)) break;
            }
            if (j == target.length()) return i;
        }
        return -1;
    }
}
