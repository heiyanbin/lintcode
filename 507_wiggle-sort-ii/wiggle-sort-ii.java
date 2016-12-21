/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/wiggle-sort-ii
@Language: Java
@Datetime: 16-06-20 08:29
*/

public class Solution {
    /**
     * @param nums a list of integer
     * @return void
     */
    public void wiggleSort(int[] nums) {
        // Write your code here
        if (nums == null || nums.length == 0) return;
        
        int l = 0, r = nums.length - 1;
        int m = -1;
        for(; l <= r;) {
            m = partition(nums, l, r);
            if (m == (nums.length - 1) / 2) break;
            else if (m < (nums.length - 1) / 2) l = m + 1;
            else r = m - 1;
        }
        
        int[] b = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            b[i] = nums[m];
        }
        
        if (nums.length % 2 == 0) {
            int small = nums.length - 2;
            int big = 1;
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] < nums[m]) {
                   b[small] = nums[i];
                   small -= 2;
                }
                else if (nums[i] > nums[m]) {
                    b[big] = nums[i];
                    big += 2;
                }
            }
        }
        else {
            int small = 0, big = nums.length - 2;
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] < nums[m]) {
                    b[small] = nums[i];
                    small += 2;
                }
                else if (nums[i] > nums[m]) {
                    b[big] = nums[i];
                    big -= 2;
                }
            }
        }
        
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = b[i];
        }
    }
    
    private int partition(int[] A, int l, int r) {
        int i = l;
        for (int j = i + 1; j <= r; ++j) {
            if (A[j] < A[l]) {
                int temp = A[++i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        int temp = A[l];
        A[l] = A[i];
        A[i] = temp;
        
        return i;
    }
}
