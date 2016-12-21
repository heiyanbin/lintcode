/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: Java
@Datetime: 14-11-11 06:06
*/

class Solution {

    /*
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    public String rotateString(String A, int offset) {
        // wirte your code here
        if(A==null ||A.isEmpty()) return A;
        char[] s = A.toCharArray();
        offset = offset%s.length;
        reverse(s,0,s.length-offset-1);
        reverse(s,s.length-offset, s.length-1);
        reverse(s,0,s.length-1);
        return new String(s);
        
    }
    private void reverse(char[] s, int l, int r)
    {
        for(;l<r; l++,r--)
        {
            char c = s[l];
            s[l]=s[r];
            s[r]=c;
        }
    }
};
