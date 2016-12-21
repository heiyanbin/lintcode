/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/paint-house-ii
@Language: C++
@Datetime: 16-06-14 04:36
*/

class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        
        vector<vector<int>> f(2, vector<int>(k));
        int minimum = 0, secondMin = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                int low;
                if (f[(i - 1) % 2][j] != minimum) 
                    low = minimum;
                else 
                    low = secondMin;
                
                f[i % 2][j] = low + costs[i - 1][j];
            }
            
            minimum = INT_MAX, secondMin = INT_MAX;
            for (int x : f[i % 2]) {
                if (x < minimum) {
                    secondMin = minimum;
                    minimum = x;
                    
                }
                else if (x < secondMin) secondMin = x;
            }
        }
        
        int ans = INT_MAX;
        for (int x : f[n % 2]) {
            ans = min(ans, x);
        }
        
        return ans;
    }
};