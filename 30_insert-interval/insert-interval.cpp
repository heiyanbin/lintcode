/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 14-10-31 07:41
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        for(auto it= intervals.begin();it!=intervals.end();)
        {
            if(newInterval.end<it->start)
            {
                intervals.insert(it,newInterval);
                return intervals;
            }
            else if(newInterval.start>it->end)
                it++;
            else
            {
                newInterval.start=min(newInterval.start,it->start);
                newInterval.end=max(newInterval.end,it->end);
                it= intervals.erase(it);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};
