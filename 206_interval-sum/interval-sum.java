/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/interval-sum
@Language: Java
@Datetime: 15-05-27 00:54
*/

/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */
public class Solution {
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    public ArrayList<Long> intervalSum(int[] A, 
                                       ArrayList<Interval> queries) {
        // write your code here
        long[] preSum = new long[A.length + 1];
        for (int i = 0; i < A.length; i++)
            preSum[i + 1] = preSum[i] + A[i];
        
        ArrayList<Long> res = new ArrayList<Long>();
        for (Interval q : queries)
            res.add(preSum[q.end + 1] - preSum[q.start]); 
            
        return res;
    }
}

