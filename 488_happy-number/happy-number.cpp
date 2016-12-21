/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 15-12-14 06:16
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        function<int(int)> next = [&](int x)->int {
            int sum = 0;
            for (; x != 0; x /= 10) {
                sum += (x % 10) * (x % 10);
            }
            return sum;
        };
        unordered_set<int> s;
        for (; n != 1; n = next(n)) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
        }
        return true;
    }
};