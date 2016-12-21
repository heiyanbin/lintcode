/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 14-10-19 10:15
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        int minDiff= 0x7FFF, sum=0;
        for(int i=0;i<nums.size()-2;++i)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int begin = i+1, end = nums.size()-1;
            while(begin<end)
            {
                int s= nums[i]+nums[begin]+nums[end];
                if(s==target) return s;
                if(abs(s-target)<minDiff)
                {
                    minDiff= abs(s-target);
                    sum=s;
                }
                if(s<target) ++begin;
                else --end;
            }
        }
        return sum;
    }
};

