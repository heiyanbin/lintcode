/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximum-subarray-iii
@Language: C++
@Datetime: 14-10-30 14:50
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        int n= nums.size();
        vector<vector<int>> d(k+1,vector<int>(n+1));
        int maxSum = INT_MIN;
        for(int i=1;i<=k;++i)
        {
            for(int j=i;j<=n;++j)
            {
                d[i-1][j-1] = j-2 >0 && j>i ? max(d[i-1][j-1],d[i-1][j-2]) : d[i-1][j-1];
                d[i][j] = j==i ? d[i-1][j-1]+nums[j-1] : max(d[i-1][j-1]+nums[j-1], d[i][j-1]+nums[j-1]);
                if(i==k)
                    maxSum = max(d[i][j],maxSum);
            }
        }
        return maxSum;
    }
};

