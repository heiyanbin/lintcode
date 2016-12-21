/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: C++
@Datetime: 15-07-06 11:53
*/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> d;
        for (int e : nums) {
            int i = upper(d, e);
            if (i < d.size()) d[i] = e;
            else d.push_back(e);
        }
        return d.size();
    }
    
    int upper(vector<int> &A, int x) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (A[m] <= x) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};

