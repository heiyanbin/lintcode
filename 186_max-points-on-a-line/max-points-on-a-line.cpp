/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/max-points-on-a-line
@Language: C++
@Datetime: 15-06-18 13:13
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<double, int> m;
            int duplicates = 0, verticalLine = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[j].x == points[i].x && points[j].y == points[i].y)
                    duplicates++;
                else {
                    if (points[j].x == points[i].x)
                        verticalLine++;
                    else {
                        double a = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                        auto it = m.find(a);
                        if (it == m.end()) m[a] = 1;
                        else it->second += 1;
                    }
                }
            }
            res = max(res, verticalLine + duplicates + 1);
            for (auto &e : m) {
                res = max(res, e.second + duplicates + 1);
            }
        }
        return res;
    }
};
