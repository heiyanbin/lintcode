/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 15-01-13 09:14
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        long long w[] = {3,5,7}, t[] = {0, 0, 0};
        vector<long long> v = vector<long long>(w, w + 3);
        if (k <= v.size()) return v[k - 1];
        
        while (v.size() < k) {
            long long x = LONG_MAX;
            for (int i = 0; i < 3; i++) {
                for (int j = t[i]; j < v.size(); j++) {
                    if (w[i] * v[j] > v.back()) {
                        x = min(x, w[i] * v[j]);
                        t[i] = j;
                        break;
                    }
                }
            }
            v.push_back(x);
        }
        return v.back();
    }
};
