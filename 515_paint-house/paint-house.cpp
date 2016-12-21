/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/paint-house
@Language: C++
@Datetime: 16-06-12 08:59
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) return 0;
        
        int endWithRed = costs[0][0];
        int endWithBlue = costs[0][1];
        int endWithGreen = costs[0][2];
        
        for (int i = 1; i < costs.size(); ++i) {
            int endWithRed1 = min(endWithBlue, endWithGreen) + costs[i][0];
            int endWithBlue1 = min(endWithRed, endWithGreen) + costs[i][1];
            int endWithGreen1 = min(endWithRed, endWithBlue) + costs[i][2];
            
            endWithRed = endWithRed1;
            endWithBlue = endWithBlue1;
            endWithGreen = endWithGreen1;
        }
        
        return min(endWithRed, min(endWithBlue, endWithGreen));
    }
};