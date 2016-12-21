/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 15-09-19 05:06
*/

#include <vector>

using namespace std;


class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN, curSum = -1;
        for (int e : nums) {
            if (curSum > 0) curSum += e;
            else curSum = e;
            if (curSum > maxSum) maxSum = curSum;
        }
        return maxSum;
    }
};

