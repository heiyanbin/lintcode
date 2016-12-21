/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: Java
@Datetime: 16-06-20 13:01
*/

public class Solution {
    /**
     * @param n an integer
     * @return a square matrix
     */
    public int[][] generateMatrix(int n) {
        // Write your code here
        int[][] a = new int[n][n];
        int x = 1;
        
        int l = 0, r = n - 1;
        for (; l < r;) {
            for (int i = l; i < r; ++i) {
                a[l][i] = x++;
            }
            for (int i = l; i < r; ++i) {
                a[i][r] = x++;
            }
            
            for (int i = r; i > l; --i) {
                a[r][i] = x++;
            }
            for (int i = r; i > l; --i) {
                a[i][l] = x++;
            }
            ++l; --r;
        }
        if (l == r) a[l][r] = x++;
        
        return a;
    }
}