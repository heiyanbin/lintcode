/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: C++
@Datetime: 16-06-12 08:30
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        int endWithOne = k * (k - 1), endWithTwo = k;
        for (int i = 3; i <=n; ++i) {
            int newEndWithOne = endWithOne * (k - 1) + endWithTwo * (k - 1);
            int newEndWithTwo = endWithOne;
            
            endWithOne = newEndWithOne;
            endWithTwo = newEndWithTwo;
        }
        
        return endWithOne + endWithTwo;
    }
};