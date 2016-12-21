/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: Java
@Datetime: 16-06-20 08:41
*/

public class Solution {
    /**
     * @param A an integer array
     * @return void
     */
    public void sortIntegers(int[] A) {
        // Write your code here
        for (int i = 1; i < A.length; ++i) {
            int j = i - 1;
            int temp = A[i];
            for (; j >= 0 && temp < A[j]; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
    }
}