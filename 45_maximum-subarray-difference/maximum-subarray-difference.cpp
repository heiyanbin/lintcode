/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximum-subarray-difference
@Language: C++
@Datetime: 14-10-19 08:15
*/

#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n= nums.size();
        vector<int> backMax(n,nums[n-1]), backMin(n,nums[n-1]);
        int maxEndWith = nums[n-1], minEndWith = nums[n-1];
        for(int i=n-2;i>=0;--i)
        {
            maxEndWith=max(maxEndWith+nums[i],nums[i]);
            backMax[i]=max(backMax[i+1],maxEndWith);
            minEndWith=min(minEndWith+nums[i],nums[i]);
            backMin[i]=min(backMin[i+1],minEndWith);
        }
        maxEndWith=nums[0]; 
        minEndWith=nums[0];
        int result =max(maxEndWith-backMin[1],backMax[1]-minEndWith);
        for(int i=1;i<n-1;i++)
        {
            maxEndWith= max(maxEndWith+nums[i],nums[i]);
            minEndWith =min(minEndWith+nums[i],nums[i]);
            result = max(result,max(maxEndWith-backMin[i+1],backMax[i+1]-minEndWith));
        }
        return result;
    }
};

