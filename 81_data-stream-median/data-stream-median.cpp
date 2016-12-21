/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/data-stream-median
@Language: C++
@Datetime: 14-12-08 12:58
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int> L;
        priority_queue<int,vector<int>, greater<int>> R;
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            if(L.empty()||nums[i]<L.top())
                L.push(nums[i]);
            else
                R.push(nums[i]);
            if(L.size()>R.size()+1)
            {
                R.push(L.top());
                L.pop();
            }
            else if(L.size()<R.size())
            {
                L.push(R.top());
                R.pop();
            }
            res.push_back(L.top());
        }
        return res;
    }
};

