/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: Java
@Datetime: 15-05-14 06:29
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

class Solution {
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: A new interval.
     * @return: A new sorted interval list.
     */
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> result = new ArrayList<Interval>();

        int i = 0;
        // proceding intervals
        while (i < intervals.size() && intervals.get(i).end < newInterval.start) {
            result.add(intervals.get(i));
            i++;
        }
        //overlaping  intervals, just keeps a longest one
        for (; i < intervals.size() && intervals.get(i).start <= newInterval.end; i++) {
            newInterval.start = Math.min(newInterval.start, intervals.get(i).start);
            newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
        }
        result.add(newInterval);
        
        // intervals going behind
        for (; i < intervals.size(); i++)
            result.add(intervals.get(i));
        
        return result;
    }
}
