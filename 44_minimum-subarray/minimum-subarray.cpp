/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 14-10-19 07:24
*/

#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int minEndWith = nums[0], result= nums[0];
        for(int i=1;i<nums.size();++i)
        {
            minEndWith = min(minEndWith+nums[i],nums[i]);
            result = min(result, minEndWith);
        }
        return result;
    }
};

