/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 14-10-19 10:05
*/

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;++i)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int begin = i+1, end= nums.size()-1;
            while(begin<end)
            {
                if(nums[begin]+nums[end]==-nums[i])
                {
                    res.push_back({nums[i],nums[begin],nums[end]});
                    begin++;end--;
                    while(nums[begin]==nums[begin-1])
                        begin++;
                    while(nums[end]==nums[end+1])
                        end--;
                }
                else if(nums[begin]+nums[end]<-nums[i])
                    ++begin;
                else
                    --end;
            }
        }
        return res;
    }
};

