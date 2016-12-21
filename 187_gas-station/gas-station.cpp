/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: C++
@Datetime: 15-04-14 05:59
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        
        int balance = 0, total = 0, n = gas.size(), start = 0;
        for (int i = 0; i < n; ++i) {
            balance += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (balance < 0) {
                start = i + 1;
                balance = 0;
            }
        }
        if (total >= 0) return start;
        else return -1;
    }
};
