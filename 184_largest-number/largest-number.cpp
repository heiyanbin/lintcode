/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 15-02-13 06:07
*/

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        string res;
        bool isZero = true;
        for (int &e : num) {
            if (res.empty() && e == 0) continue;
            res.append(to_string(e));
            if (e != 0) isZero = false;
        }
        return isZero ? "0" : res;
    }
    static bool cmp (int a, int b) {
        string ab = to_string(a) + to_string(b), ba = to_string(b) + to_string(a);
        for (int i = 0; i < ab.size(); ++ i) {
            if (ab[i] > ba[i]) return true;
            if (ab[i] < ba[i]) return false;
        }
        return false;
    }
};
