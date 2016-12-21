/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/number-of-airplanes-in-the-sky
@Language: C++
@Datetime: 15-05-13 08:13
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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, int>> times;
        for (auto &it : airplanes) {
            times.push_back(make_pair(it.start, 1));
            times.push_back(make_pair(it.end, 0));
        }
        sort(times.begin(), times.end());
        int maxNum = 0, curNum = 0;
        for (auto &t : times) {
            if (t.second == 1) curNum++;
            else curNum--;
            maxNum = max(maxNum, curNum);
        }
        return maxNum;
    }
};
