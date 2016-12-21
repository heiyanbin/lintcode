/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-06-12 03:49
*/

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        if (size <= originalStr.size()) return originalStr;
        string s(size, padChar);
        for (int i = originalStr.size() - 1, j = s.size() - 1; j >= 0 && i >= 0; ) {
            s[j--] = originalStr[i--];
        }
        return s;
    }
};