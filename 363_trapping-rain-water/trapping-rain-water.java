/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: Java
@Datetime: 15-05-05 01:35
*/

public class Solution {
    /**
     * @param heights: an array of integers
     * @return: a integer
     */
    public int trapRainWater(int[] heights) {
        // write your code here
        int[] leftHighest = new int[heights.length];
        for (int i = 1; i < heights.length; ++i)
            leftHighest[i] = Math.max(leftHighest[i - 1], heights[i - 1]);
       
        int rightHighest = 0, area = 0;
        for (int i = heights.length - 2; i >= 0; --i) {
            rightHighest = Math.max(rightHighest, heights[i + 1]);
            int h = Math.min(leftHighest[i], rightHighest);
            if (h > heights[i])
                area += h - heights[i];
        }
        return area;
    }
}
