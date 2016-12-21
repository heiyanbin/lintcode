/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: C++
@Datetime: 14-12-12 02:14
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size()<=1) return 0;
        vector<int> d(prices.size());
        for(int i= prices.size()-2, x=0; i>=0;--i) {
            x = max(prices[i+1]-prices[i]+x,0);
            d[i]=max(d[i+1],x);
        }
        int max_profit=0;
        for(int i=0,x=0;i<prices.size();++i) {
            x= i>0 ? max(prices[i]-prices[i-1] + x,0) : 0;
            max_profit = max(max_profit, x + d[i]);
        }
        return max_profit;
    }
};
