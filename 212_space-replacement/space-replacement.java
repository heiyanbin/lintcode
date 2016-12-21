/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: Java
@Datetime: 15-06-05 03:56
*/

public class Solution {
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    public int replaceBlank(char[] string, int length) {
        // Write your code here
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ')
                ++count;
        }
        int newLen = length + count * 2;
        
        for (int i = newLen - 1, j = length - 1; j >= 0; --j) {
            if (string[j] != ' ') 
                string[i--] = string[j];
            else {
                string[i--] = '0';
                string[i--] = '2';
                string[i--] = '%';
            }
        }
        return newLen;
    }
}
