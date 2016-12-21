/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: Java
@Datetime: 16-06-20 12:49
*/

public class Solution {
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer list
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        // Write your code here
        List<Integer> ans = new ArrayList<Integer>();
        
        if (matrix == null) return ans;
        
        int m = matrix.length;
        if (m == 0) return ans;
        
        int n = matrix[0].length;
        if (n == 0) return ans;
        
        int l = 0, r = n - 1, t = 0, b = m - 1;
        for (; ;) {
            for (int i = l; i <= r; ++i) {
                ans.add(matrix[t][i]);
            }
            ++t;
            if (t > b) break;
            
            for (int i = t; i <= b; ++i) {
                ans.add(matrix[i][r]);
            }
            --r;
            if (r < l) break;
            
            for (int i = r; i >= l; --i) {
                ans.add(matrix[b][i]);
            }
            --b;
            if (b < t) break;
            
            for (int i = b; i >= t; --i) {
                ans.add(matrix[i][l]);
            }
            ++l;
            if (l > r) break;
        }
        
        return ans;
    }
}