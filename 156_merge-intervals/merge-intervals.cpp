/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 15-05-24 04:47
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
            -> bool {return a.start < b.start;});
        vector<Interval> res;
        for (auto &e : intervals) {
            if (res.empty() || e.start > res.back().end)
                res.push_back(e);
            else
                res.back().end = max(res.back().end, e.end);
        }
        return res;
    }
};
