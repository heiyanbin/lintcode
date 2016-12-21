/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: Java
@Datetime: 16-06-20 08:51
*/

public class Solution {
    /**
     * @param A an integer array
     * @return void
     */
    public void sortIntegers2(int[] A) {
        // Write your code here
        if (A == null || A.length <= 1) return;
        int[] aux = new int[A.length];
        sort(A, 0, A.length - 1, aux);
    }
    
    private void sort(int[] A, int l, int r, int [] aux) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        sort(A, l, m, aux);
        sort(A, m + 1, r, aux);
        
        for (int i = l, j = m + 1, k = l; k <= r; ++k) {
            if (i > m) aux[k] = A[j++];
            else if (j > r) aux[k] = A[i++];
            else if (A[i] < A[j]) aux[k] = A[i++];
            else aux[k] = A[j++];
        }
        
        for (int k = l; k <= r; ++k) {
            A[k] = aux[k];
        }
    }
}