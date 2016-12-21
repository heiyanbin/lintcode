/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-adjustment-cost
@Language: C++
@Datetime: 15-01-13 06:07
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     * dp state definition: f[i][j] means: for the A[0, i] subarray, adjut
     * A[i] to value j, the minimum ajustment cost 
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        if (A.size() < 2) return 0;
        vector<int> d(101), e(101);
        int minCost =INT_MAX;
        for (int i = 0; i < A.size(); ++i, d = e) {
            for (int j = 0; j <= 100; ++j) {
                e[j] = INT_MAX;
                for (int k = max(j - target, 0); k <= min(j + target, 100); ++k)
                    e[j] = min(e[j], d[k] + abs(A[i] - j));
                if (i == A.size() - 1)
                    minCost = min(minCost, e[j]);
            }
        }
        return minCost;
    }
};
