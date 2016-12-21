/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/super-ugly-number
@Language: C++
@Datetime: 16-06-12 05:45
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        
        set<long long> pq;
        pq.insert(1);
        int cur = 1;
        for (int k = 0; ; ++k) {
            cur = *pq.begin();
            if (k == n - 1) break;
            pq.erase(pq.begin());
            for (long long x : primes) {
                pq.insert(cur * x);
            }
        }
        return cur;
    }
};