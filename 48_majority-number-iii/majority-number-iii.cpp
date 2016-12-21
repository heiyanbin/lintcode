/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 14-10-31 06:32
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int,int> c;
        int i=0;
        for(;c.size()<k && i<nums.size();i++)
            c[nums[i]]++;
        for(;i<nums.size();i++)
        {
            if(c.find(nums[i])!=c.end())
                c[nums[i]]++;
            else
            {
                if(c.size()<k)
                    c[nums[i]]=1;
                else
                {
                    for(auto it=c.begin();it!=c.end();)
                    {
                        it->second--;
                        if(it->second==0)
                            it = c.erase(it);
                        else
                            it++;
                    }
                }
            }
        }
        int major, maxNum = INT_MIN;
        for(auto it=c.begin();it!=c.end();it++)
        {
            if(it->second>maxNum)
            {
                maxNum = it->second;
                major = it->first;
            }
        }
        return major;
    }
};

