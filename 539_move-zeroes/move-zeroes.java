/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: Java
@Datetime: 16-06-20 08:57
*/

public class Solution {
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    public void moveZeroes(int[] nums) {
        // Write your code here
        for (int i = 0, j = 0; j < nums.length; ++j) {
            if (nums[j] != 0) {
                int temp = nums[i];
                nums[i++] = nums[j];
                nums[j] = temp;
            }
        }
    }
}