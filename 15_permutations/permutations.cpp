/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/permutations
@Language: C++
@Datetime: 14-10-19 09:03
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return res;
        DFS(nums,0);
        return res;
    }
    void DFS(vector<int> &nums,int t)
    {
        if(t==nums.size())
            res.push_back(nums);
        else
        {
            for(int i=t;i<nums.size();++i)
            {
                swap(nums[i],nums[t]);
                DFS(nums,t+1);
                swap(nums[i],nums[t]);
            }
        }
    }
    vector<vector<int>> res;
};

